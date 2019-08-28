import math
import time

# BigO is passed to a benchmark in order to specify the asymptotic computational complexity for the
# benchmark. In case AUTO is selected, complexity will be calculated automatically to the best fit.
(ONE, LOGN, N, N_LOGN, N_SQUARED, N_SQUARED_LOGN, N_CUBED, TWO_POWER_N,
 N_FACTORIAL, NONE, AUTO) = range(11)


# This data structure will contain the result returned by MinimalLeastSq.
#   - coef        : Estimated coefficient for the high-order term as interpolated from data
#   - rms         : Normalized Root Mean Squared Error
#   - complexity  : Scalability form (e.g. BigO.N, BigO.N_LOGN). In case a scalability form has
#                   been provided to MinimalLeastSq this will return the same value. In case
#                   BigO.AUTO has been selected, this parameter will return the best fitting curve
#                   detected.
class LeastSq:
    def __init__(self):
        self.coef = 0.0
        self.rms = 0.0
        self.complexity = NONE


# Internal function to calculate the different scalability forms.
def fitting_curve(complexity):
    return {
        N: lambda n: n,
        N_SQUARED: lambda n: n**2,
        N_CUBED: lambda n: n**3,
        LOGN: lambda n: float('-inf') if n == 0 else math.log2(n),
        N_LOGN: lambda n: float('-inf') if n == 0 else n * math.log2(n),
        N_SQUARED_LOGN: lambda n: float('-inf')
        if n == 0 else n * n * math.log2(n),
        TWO_POWER_N: lambda n: 2**n,
        N_FACTORIAL: lambda n: math.factorial(int(n)),
    }.get(complexity, lambda n: 1.0)


# Function to return an string for the calculated complexity.
def get_big_o_string(complexity):
    return {
        N: 'n',
        N_SQUARED: 'n^2',
        N_CUBED: 'n^3',
        LOGN: 'logn',
        N_LOGN: 'nlogn',
        N_SQUARED_LOGN: 'n^2logn',
        TWO_POWER_N: '2^n',
        N_FACTORIAL: 'n!',
        ONE: '1',
    }.get(complexity, 'f(n)')


def minimal_least_sq_with_curve(n, time, curve):
    sigma_gn_squared = sum(curve(each_n)**2 for each_n in n)
    sigma_time = sum(each_time for each_time in time)
    sigma_time_gn = sum(each_time * curve(each_n)
                        for each_time, each_n in zip(time, n))

    result = LeastSq()

    result.coef = sigma_time_gn / sigma_gn_squared
    rms = sum((each_time - result.coef * curve(each_n))**2
              for each_time, each_n in zip(time, n))
    mean = sigma_time / len(n)
    result.rms = math.sqrt(rms / len(n)) / mean

    return result


def find_maximum_power(max_n):
    if max_n > 250000000.0:
        return N
    elif max_n > 2500000.0:
        return N_LOGN
    elif max_n > 2500.0:
        return N_SQUARED
    elif max_n > 250.0:
        return N_CUBED
    elif max_n > 25.0:
        return TWO_POWER_N
    elif max_n > 11.0:
        return N_FACTORIAL
    return NONE


def minimal_least_sq(n, time, complexity):
    best_fit = LeastSq()

    if complexity == AUTO:
        fit_curves = (ONE, LOGN, N, N_LOGN, N_SQUARED, N_SQUARED_LOGN, N_CUBED,
                      TWO_POWER_N, N_FACTORIAL)
        # Filter fit_curves as we cannot try all possible curves which might overflow for some n.
        fit_curves = fit_curves[:find_maximum_power(max(n))]

        best_fit = minimal_least_sq_with_curve(n, time, fitting_curve(ONE))
        best_fit.complexity = ONE

        for fit in fit_curves:
            current_fit = minimal_least_sq_with_curve(n, time,
                                                      fitting_curve(fit))
            if current_fit.rms < best_fit.rms:
                best_fit = current_fit
                best_fit.complexity = fit
    else:
        best_fit = minimal_least_sq_with_curve(n, time,
                                               fitting_curve(complexity))
        best_fit.complexity = complexity

    return best_fit


def power_to_complexity(power):
    return int(round(2.0 * power))


def get_big_o_string_multiple_params(metric_names, power, oper):
    def create_symbol_with_complexity(symbol, complexity):
        if complexity == ONE:
            return ''
        elif complexity == LOGN:
            return f'log({symbol})'
        elif complexity == N:
            return f'{symbol}'
        elif complexity == N_LOGN:
            return f'{symbol}log({symbol})'
        elif complexity in (N_SQUARED, N_SQUARED_LOGN, N_CUBED):
            power = 0.5 * complexity
            return '{}^{}'.format(symbol, int(
                math.floor(power))) + ('' if math.isclose(
                    power, math.floor(power)) else f'log({symbol})')
        elif complexity == TWO_POWER_N:
            return f'2^({symbol})'
        elif complexity == N_FACTORIAL:
            return f'({symbol})!'
        return ''

    result = create_symbol_with_complexity(metric_names[0],
                                           power_to_complexity(power[0]))
    for s, p, o in zip(metric_names[1:], power[1:], oper):
        term = create_symbol_with_complexity(s, power_to_complexity(p))
        if term:
            result += (o if result else '') + term
    return 'O(' + (result if result else '1') + ')'


def minimal_least_sq_multiple_params(metric_names, metrics, iter_times,
                                     timeout):
    calc_time_start = time.perf_counter()

    def generate_expression(metrics):
        powers, opers = [], []

        def compute_max_n_for_each_param(metrics):
            return [max(param_col) for param_col in zip(*metrics)]

        def generate_expression_helper(max_n_for_params, param_idx, power_buf,
                                       oper_buf):
            if param_idx == len(max_n_for_params) - 1:
                for p in range(find_maximum_power(
                        max_n_for_params[param_idx])):
                    powers.append(power_buf + [0.5 * p])
                    opers.append(oper_buf)
                return
            for p in range(find_maximum_power(max_n_for_params[param_idx])):
                for o in ('+', '*'):
                    generate_expression_helper(max_n_for_params, param_idx + 1,
                                               power_buf + [0.5 * p],
                                               oper_buf + [o])

        generate_expression_helper(compute_max_n_for_each_param(metrics), 0,
                                   [], [])
        return powers, opers

    powers, opers = generate_expression(metrics)

    def reduce_according_oper(metric, power, oper):
        prev = result = fitting_curve(power_to_complexity(power[0]))(metric[0])
        for x, p, op in zip(metric[1:], power[1:], oper):
            curve = fitting_curve(power_to_complexity(p))
            if op == '+':
                prev = curve(x)
                result += curve(x)
            else:
                prev = prev * curve(x)
                result += prev * curve(x) - prev
        return result

    closest_power_oper = None
    least_rms = float('inf')
    for i, (power, oper) in enumerate(zip(powers, opers)):
        if i % 1024 == 0 and timeout != 0:
            calc_time_current = time.perf_counter()
            if calc_time_current - calc_time_start > timeout:
                return 'TIMEOUT'

        n = [reduce_according_oper(metric, power, oper) for metric in metrics]
        if any(not math.isfinite(d) for d in n):
            continue

        result = minimal_least_sq(n, iter_times, N)
        if result.rms < least_rms:
            least_rms = result.rms
            closest_power_oper = (power, oper)
    return get_big_o_string_multiple_params(metric_names, *closest_power_oper)
