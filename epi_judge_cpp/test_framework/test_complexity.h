
#pragma once

#include <algorithm>
#include <chrono>
#include <cmath>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace test_framework {
namespace test_complexity {

// BigO is passed to a benchmark in order to specify the asymptotic
// computational complexity for the benchmark. In case AUTO is selected,
// complexity will be calculated automatically to the best fit.
enum BigO {
  ONE,
  LOGN,
  N,
  N_LOGN,
  N_SQUARED,
  N_SQUARED_LOGN,
  N_CUBED,
  TWO_POWER_N,
  N_FACTORIAL,
  NONE,
  AUTO
};

// This data structure will contain the result returned by MinimalLeastSq.
//   - coef        : Estimated coeficient for the high-order term as
//                   interpolated from data.
//   - rms         : Normalized Root Mean Squared Error
//   - complexity  : Scalability form (e.g. N, N_LOGN). In case a scalability
//                   form has been provided to MinimalLeastSq this will return
//                   the same value. In case BigO::AUTO has been selected,
//                   this parameter will return the best fitting curve
//                   detected.
struct LeastSq {
  double coef = 0.0;
  double rms = 0.0;
  BigO complexity = NONE;
};

double Factorial(int n) {
  double result = 1.0;
  for (int i = 2; i <= n; ++i) {
    result *= i;
  }
  return result;
}

// Internal function to calculate the different scalability forms.
std::function<double(double)> FittingCurve(BigO complexity) {
  switch (complexity) {
    case N:
      return [](double n) -> double { return n; };
    case N_SQUARED:
      return [](double n) -> double { return n * n; };
    case N_CUBED:
      return [](double n) -> double { return n * n * n; };
    case LOGN:
      return [](double n) { return std::log2(n); };
    case N_LOGN:
      return [](double n) { return n * std::log2(n); };
    case N_SQUARED_LOGN:
      return [](double n) { return n * n * std::log2(n); };
    case TWO_POWER_N:
      return [](double n) { return pow(2, n); };
    case N_FACTORIAL:
      return [](double n) { return Factorial(static_cast<int>(n)); };
    case ONE:
    default:
      return [](double) { return 1.0; };
  }
}

// Function to return an string for the calculated complexity.
std::string GetBigOString(BigO complexity) {
  switch (complexity) {
    case N:
      return "n";
    case N_SQUARED:
      return "n^2";
    case N_CUBED:
      return "n^3";
    case LOGN:
      return "logn";
    case N_LOGN:
      return "nlogn";
    case N_SQUARED_LOGN:
      return "n^2logn";
    case TWO_POWER_N:
      return "2^n";
    case N_FACTORIAL:
      return "n!";
    case ONE:
      return "1";
    default:
      return "f(n)";
  }
}

// Find the coefficient for the high-order term in the running time, by
// minimizing the sum of squares of relative error, for the fitting curve
// given by the lambda expresion.
//   - n             : Vector containing the size of the benchmark tests
//   - time          : Vector containing the times for the benchmark tests
//   - curve         : lambda expresion of a curve
LeastSq MinimalLeastSqWithCurve(const std::vector<double>& n,
                                const std::vector<long long>& time,
                                std::function<double(int)> curve) {
  double sigma_gn = 0.0;
  double sigma_gn_squared = 0.0;
  double sigma_time = 0.0;
  double sigma_time_gn = 0.0;

  // Calculate least square fitting parameter.
  for (int i = 0; i < n.size(); ++i) {
    double gn_i = curve(n[i]);
    sigma_gn += gn_i;
    sigma_gn_squared += gn_i * gn_i;
    sigma_time += time[i];
    sigma_time_gn += time[i] * gn_i;
  }

  LeastSq result;

  // Calculate complexity.
  result.coef = sigma_time_gn / sigma_gn_squared;

  // Calculate RMS.
  double rms = 0.0;
  for (int i = 0; i < n.size(); ++i) {
    double fit = result.coef * curve(n[i]);
    rms += pow(time[i] - fit, 2);
  }

  // Normalized RMS by the mean of the observed values.
  double mean = sigma_time / n.size();
  result.rms = sqrt(rms / n.size()) / mean;

  return result;
}

int FindMaximumPower(double max_n) {
  if (max_n > 250000000.0) {
    return static_cast<int>(N);
  } else if (max_n > 2500000.0) {
    return static_cast<int>(N_LOGN);
  } else if (max_n > 2500.0) {
    return static_cast<int>(N_SQUARED);
  } else if (max_n > 250.0) {
    return static_cast<int>(N_CUBED);
  } else if (max_n > 25.0) {
    return static_cast<int>(TWO_POWER_N);
  } else if (max_n > 11.0) {
    return static_cast<int>(N_FACTORIAL);
  }
  return static_cast<int>(NONE);
}

// Find the coefficient for the high-order term in the running time, by
// minimizing the sum of squares of relative error
//   - n          : Vector containing the size of the benchmark tests
//   - time       : Vector containing the times for the benchmark tests
//   - complexity : If different than AUTO, the fitting curve will stick to
//                  this one. If it is AUTO, it will be calculated the best
//                  fitting curve.
LeastSq MinimalLeastSq(const std::vector<double>& n,
                       const std::vector<long long>& time,
                       const BigO complexity) {
  LeastSq best_fit;

  if (complexity == AUTO) {
    std::vector<BigO> fit_curves = {ONE,     LOGN,        N,
                                    N_LOGN,  N_SQUARED,   N_SQUARED_LOGN,
                                    N_CUBED, TWO_POWER_N, N_FACTORIAL};
    // Filter fit_curves as we cannot try all possible curves which might
    // overflow for some n.
    fit_curves = {fit_curves.begin(),
                  fit_curves.begin() + FindMaximumPower(*std::max_element(
                                           std::begin(n), std::end(n)))};

    // Take ONE as default best fitting curve.
    best_fit = MinimalLeastSqWithCurve(n, time, FittingCurve(ONE));
    best_fit.complexity = ONE;

    // Compute all possible fitting curves and stick to the best one.
    for (const BigO& fit : fit_curves) {
      LeastSq current_fit =
          MinimalLeastSqWithCurve(n, time, FittingCurve(fit));
      if (current_fit.rms < best_fit.rms) {
        best_fit = current_fit;
        best_fit.complexity = fit;
      }
    }
  } else {
    best_fit = MinimalLeastSqWithCurve(n, time, FittingCurve(complexity));
    best_fit.complexity = complexity;
  }

  return best_fit;
}

void GenerateExpression(const std::vector<int> max_n_for_params,
                        int param_idx, std::vector<double>* power_buf,
                        std::vector<std::vector<double>>* powers,
                        std::vector<std::string>* oper_buf,
                        std::vector<std::vector<std::string>>* opers) {
  if (param_idx == max_n_for_params.size() - 1) {
    for (int p = 0; p < FindMaximumPower(
                            static_cast<double>(max_n_for_params[param_idx]));
         ++p) {
      power_buf->emplace_back(0.5 * p);
      powers->emplace_back(*power_buf);
      power_buf->pop_back();
      opers->emplace_back(*oper_buf);
    }
    return;
  }
  for (int p = 0;
       p < FindMaximumPower(static_cast<double>(max_n_for_params[param_idx]));
       ++p) {
    power_buf->emplace_back(0.5 * p);
    for (const std::string& o : {"+", "*"}) {
      oper_buf->emplace_back(o);
      GenerateExpression(max_n_for_params, param_idx + 1, power_buf, powers,
                         oper_buf, opers);
      oper_buf->pop_back();
    }
    power_buf->pop_back();
  }
}

BigO PowerToComplexity(double power) {
  return static_cast<BigO>(int(std::round(2.0 * power)));
}

double ReduceAccordingOper(const std::vector<int>& metric,
                           const std::vector<double>& power,
                           const std::vector<std::string>& oper) {
  double prev = FittingCurve(PowerToComplexity(power[0]))(
      static_cast<double>(metric[0]));
  double result = prev;
  for (int i = 1; i < metric.size(); ++i) {
    auto curve = FittingCurve(PowerToComplexity(power[i]));
    if (oper[i - 1] == "+") {
      prev = curve(metric[i]);
      result += curve(metric[i]);
    } else {
      prev = prev * curve(metric[i]);
      result += prev * curve(metric[i]) - prev;
    }
  }
  return result;
}

std::string CreateSymbolWithComplexity(const std::string& symbol,
                                       BigO complexity) {
  const double power = 0.5 * static_cast<int>(complexity);
  switch (complexity) {
    case ONE:
      return "";
    case LOGN:
      return "log(" + symbol + ")";
    case N:
      return symbol;
    case N_LOGN:
      return symbol + "log(" + symbol + ")";
    case N_SQUARED:
    case N_SQUARED_LOGN:
    case N_CUBED:
      return symbol + "^" + std::to_string(static_cast<int>(floor(power))) +
             (power == floor(power) ? "" : "log(" + symbol + ")");
    case TWO_POWER_N:
      return "2^(" + symbol + ")";
    case N_FACTORIAL:
      return "(" + symbol + ")!";
    default:
      return "";
  }
}

std::string GetBigOStringMultipleParams(
    const std::vector<std::string>& metric_names,
    const std::vector<double>& power, const std::vector<std::string>& oper) {
  std::string result = CreateSymbolWithComplexity(
      metric_names[0], PowerToComplexity(power[0]));
  for (int i = 1; i < power.size(); ++i) {
    const std::string term = CreateSymbolWithComplexity(
        metric_names[i], PowerToComplexity(power[i]));
    if (!term.empty()) {
      result += (result.empty() ? "" : oper[i - 1]) + term;
    }
  }
  return "O(" + (result.empty() ? "1" : result) + ")";
}

}  // namespace test_complexity

std::vector<int> ComputeMaxNForEachParam(
    const std::vector<std::vector<int>>& metrics) {
  std::vector<int> max_n_for_params(metrics.front().size(), 1);
  for (const auto& metric : metrics) {
    for (int i = 0; i < metric.size(); ++i) {
      max_n_for_params[i] = std::max(max_n_for_params[i], metric[i]);
    }
  }
  return max_n_for_params;
}

std::string MinimalLeastSqMultipleParams(
    const std::vector<std::string>& metric_names,
    const std::vector<std::vector<int>>& metrics,
    const std::vector<long long>& iter_times,
    const std::chrono::seconds timeout) {
  auto calc_time_start = std::chrono::high_resolution_clock::now();
  std::vector<std::vector<double>> powers;
  std::vector<std::vector<std::string>> opers;
  test_complexity::GenerateExpression(
      ComputeMaxNForEachParam(metrics), 0,
      std::make_unique<std::vector<double>>().get(), &powers,
      std::make_unique<std::vector<std::string>>().get(), &opers);

  double least_rms = std::numeric_limits<double>::max();
  std::vector<double> closest_power;
  std::vector<std::string> closest_oper;

  for (int i = 0; i < powers.size(); ++i) {
    if (i % 1024 == 0 && timeout != timeout.zero()) {
      auto calc_time_current = std::chrono::high_resolution_clock::now();
      if (calc_time_current - calc_time_start > timeout) {
        return "TIMEOUT";
      }
    }

    std::vector<double> n;
    for (const std::vector<int>& metric : metrics) {
      n.emplace_back(
          test_complexity::ReduceAccordingOper(metric, powers[i], opers[i]));
    }
    if (std::any_of(n.begin(), n.end(), [](double d) {
          return std::isinf(d) || std::isnan(d);
        })) {
      continue;
    }

    const test_complexity::LeastSq result =
        test_complexity::MinimalLeastSq(n, iter_times, test_complexity::N);
    if (result.rms < least_rms) {
      least_rms = result.rms;
      closest_power = powers[i];
      closest_oper = opers[i];
    }
  }
  return test_complexity::GetBigOStringMultipleParams(
      metric_names, closest_power, closest_oper);
}

}  // namespace test_framework
