
package epi.test_framework;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.function.ToDoubleFunction;

public class TestComplexity {
  // BigO is passed to a benchmark in order to specify the asymptotic
  // computational complexity for the benchmark. In case AUTO is selected,
  // complexity will be calculated automatically to the best fit.
  public enum BigO {
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
  }

  // This data structure will contain the result returned by MinimalLeastSq.
  //   - coef        : Estimated coefficient for the high-order term as
  //                   interpolated from data
  //   - rms         : Normalized Root Mean Squared Error
  //   - complexity  : Scalability form (e.g. BigO.N, BigO.N_LOGN). In case a
  //                   scalability form has been provided to MinimalLeastSq
  //                   this will return the same value. In case BigO.AUTO
  //                   has been selected, this parameter will return the best
  //                   fitting curve detected.
  public static class LeastSq {
    public double coef = 0.0;
    public double rms = 0.0;
    BigO complexity = BigO.NONE;
  }

  private static double factorial(int n) {
    double result = 1.0;
    for (int i = 2; i <= n; ++i) {
      result *= i;
    }
    return result;
  }

  // Internal function to calculate the different scalability forms.
  private static ToDoubleFunction<Double> fittingCurve(BigO complexity) {
    switch (complexity) {
    case N:
      return (n) -> n;
    case N_SQUARED:
      return (n) -> n * n;
    case N_CUBED:
      return (n) -> n * n * n;
    case LOGN:
      return (n) -> Math.log(n) / Math.log(2);
    case N_LOGN:
      return (n) -> n * Math.log(n) / Math.log(2);
    case N_SQUARED_LOGN:
      return (n) -> n * n * Math.log(n) / Math.log(2);
    case TWO_POWER_N:
      return (n) -> Math.pow(2, n);
    case N_FACTORIAL:
      return (n) -> factorial(n.intValue());
    case ONE:
    default:
      return (n) -> 1.0;
    }
  }

  // Function to return an string for the calculated complexity.
  private static String getBigOString(BigO complexity) {
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
  //   - n             : List containing the size of the benchmark tests
  //   - time          : List containing the times for the benchmark tests
  //   - curve         : lambda expresion of a curve
  private static LeastSq
  minimalLeastSqWithCurve(List<Double> n, List<Long> time,
                          ToDoubleFunction<Double> curve) {
    double sigmaGn = 0.0;
    double sigmaGnSquared = 0.0;
    double sigmaTime = 0.0;
    double sigmaTimeGn = 0.0;

    // Calculate least square fitting parameter.
    for (int i = 0; i < n.size(); ++i) {
      double gnI = curve.applyAsDouble(n.get(i));
      sigmaGn += gnI;
      sigmaGnSquared += gnI * gnI;
      sigmaTime += time.get(i);
      sigmaTimeGn += time.get(i) * gnI;
    }

    LeastSq result = new LeastSq();

    // Calculate complexity.
    result.coef = sigmaTimeGn / sigmaGnSquared;

    // Calculate RMS.
    double rms = 0.0;
    for (int i = 0; i < n.size(); ++i) {
      double fit = result.coef * curve.applyAsDouble(n.get(i));
      rms += Math.pow(time.get(i) - fit, 2);
    }

    // Normalized RMS by the mean of the observed values.
    double mean = sigmaTime / n.size();
    result.rms = Math.sqrt(rms / n.size()) / mean;

    return result;
  }

  private static int findMaximumPower(Double maxN) {
    if (maxN > 250000000.0) {
      return BigO.N.ordinal();
    } else if (maxN > 2500000.0) {
      return BigO.N_LOGN.ordinal();
    } else if (maxN > 2500.0) {
      return BigO.N_SQUARED.ordinal();
    } else if (maxN > 250.0) {
      return BigO.N_CUBED.ordinal();
    } else if (maxN > 25.0) {
      return BigO.TWO_POWER_N.ordinal();
    } else if (maxN > 11.0) {
      return BigO.N_FACTORIAL.ordinal();
    }
    return BigO.NONE.ordinal();
  }

  // Find the coefficient for the high-order term in the running time, by
  // minimizing the sum of squares of relative error.
  //   - n          : List containing the size of the benchmark tests
  //   - time       : List containing the times for the benchmark tests
  //   - complexity : If different than AUTO, the fitting curve will stick to
  //                  this one. If it is AUTO, it will be calculated the best
  //                  fitting curve.
  private static LeastSq minimalLeastSq(List<Double> n, List<Long> time,
                                        BigO complexity) {
    LeastSq bestFit;

    if (complexity == BigO.AUTO) {
      List<BigO> fitCurves =
          List.of(BigO.ONE, BigO.LOGN, BigO.N, BigO.N_LOGN, BigO.N_SQUARED,
                  BigO.N_SQUARED_LOGN, BigO.N_CUBED, BigO.TWO_POWER_N,
                  BigO.N_FACTORIAL);
      // Filter fitCurves as we cannot try all possible curves which might
      // overflow for some n.
      fitCurves = fitCurves.subList(0, findMaximumPower(Collections.max(n)));

      // Take BigO.ONE as default best fitting curve.
      bestFit = minimalLeastSqWithCurve(n, time, fittingCurve(BigO.ONE));
      bestFit.complexity = BigO.ONE;

      // Compute all possible fitting curves and stick to the best one.
      for (BigO fit : fitCurves) {
        LeastSq currentFit =
            minimalLeastSqWithCurve(n, time, fittingCurve(fit));
        if (currentFit.rms < bestFit.rms) {
          bestFit = currentFit;
          bestFit.complexity = fit;
        }
      }
    } else {
      bestFit = minimalLeastSqWithCurve(n, time, fittingCurve(complexity));
      bestFit.complexity = complexity;
    }

    return bestFit;
  }

  private static void
  generateExpression(List<Integer> maxNForParams, Integer paramIdx,
                     List<Double> powerBuf, List<List<Double>> powers,
                     List<String> operBuf, List<List<String>> opers) {
    if (paramIdx == maxNForParams.size() - 1) {
      for (int p = 0;
           p < findMaximumPower(maxNForParams.get(paramIdx).doubleValue());
           ++p) {
        powerBuf.add(0.5 * p);
        powers.add(new ArrayList<>(powerBuf));
        powerBuf.remove(powerBuf.size() - 1);
        opers.add(new ArrayList<>(operBuf));
      }
      return;
    }
    for (int p = 0;
         p < findMaximumPower(maxNForParams.get(paramIdx).doubleValue()); ++p) {
      powerBuf.add(0.5 * p);
      for (String o : List.of("+", "*")) {
        operBuf.add(o);
        generateExpression(maxNForParams, paramIdx + 1, powerBuf, powers,
                           operBuf, opers);
        operBuf.remove(operBuf.size() - 1);
      }
      powerBuf.remove(powerBuf.size() - 1);
    }
  }

  private static BigO powerToComplexity(Double power) {
    return BigO.values()[(int)(2.0 * power)];
  }

  private static Double reduceAccordingOper(List<Integer> metric,
                                            List<Double> power,
                                            List<String> oper) {
    Double prev = fittingCurve(powerToComplexity(power.get(0)))
                      .applyAsDouble(metric.get(0).doubleValue());
    Double result = prev;
    for (int i = 1; i < metric.size(); ++i) {
      ToDoubleFunction<Double> curve =
          fittingCurve(powerToComplexity(power.get(i)));
      if (oper.get(i - 1).equals("+")) {
        prev = curve.applyAsDouble(metric.get(i).doubleValue());
        result += curve.applyAsDouble(metric.get(i).doubleValue());
      } else {
        prev = prev * curve.applyAsDouble(metric.get(i).doubleValue());
        result +=
            prev * curve.applyAsDouble(metric.get(i).doubleValue()) - prev;
      }
    }
    return result;
  }

  private static String createSymbolWithComplexity(String symbol,
                                                   BigO complexity) {
    switch (complexity) {
    case ONE:
      return "";
    case LOGN:
      return String.format("log(%s)", symbol);
    case N:
      return symbol;
    case N_LOGN:
      return String.format("%slog(%s)", symbol, symbol);
    case N_SQUARED:
    case N_SQUARED_LOGN:
    case N_CUBED:
      final double power = 0.5 * complexity.ordinal();
      return String.format("%s^%d", symbol, (int)Math.floor(power)) +
          (Double.compare(power, Math.floor(power)) == 0
               ? ""
               : String.format("log(%s)", symbol));
    case TWO_POWER_N:
      return String.format("2^(%s)", symbol);
    case N_FACTORIAL:
      return String.format("(%s)!", symbol);
    default:
      return "";
    }
  }

  private static String getBigOStringMultipleParams(List<String> metricNames,
                                                    List<Double> power,
                                                    List<String> oper) {
    StringBuilder result = new StringBuilder(createSymbolWithComplexity(
        metricNames.get(0), powerToComplexity(power.get(0))));
    for (int i = 1; i < power.size(); ++i) {
      final String term = createSymbolWithComplexity(
          metricNames.get(i), powerToComplexity(power.get(i)));
      if (!term.isEmpty()) {
        result.append(result.toString().isEmpty() ? "" : oper.get(i - 1))
            .append(term);
      }
    }
    return "O(" + (result.toString().isEmpty() ? "1" : result.toString()) + ")";
  }

  private static List<Integer>
  computeMaxNForEachParam(List<List<Integer>> metrics) {
    List<Integer> maxNForParams =
        new ArrayList<>(Collections.nCopies(metrics.get(0).size(), 1));
    for (List<Integer> metric : metrics) {
      for (int i = 0; i < metric.size(); ++i) {
        maxNForParams.set(i, Math.max(maxNForParams.get(i), metric.get(i)));
      }
    }
    return maxNForParams;
  }

  public static String minimalLeastSqMultipleParams(List<String> metricNames,
                                                    List<List<Integer>> metrics,
                                                    List<Long> iterTimes,
                                                    long timeout) {
    long calcTimeStart = System.nanoTime();
    List<List<Double>> powers = new ArrayList<>();
    List<List<String>> opers = new ArrayList<>();
    generateExpression(computeMaxNForEachParam(metrics), 0, new ArrayList<>(),
                       powers, new ArrayList<>(), opers);

    Double leastRms = Double.MAX_VALUE;
    List<Double> closestPower = null;
    List<String> closestOper = null;
    for (int i = 0; i < powers.size(); ++i) {
      if (i % 1024 == 0 && timeout != 0) {
        long calcTimeCurrent = System.nanoTime();
        if (calcTimeCurrent - calcTimeStart > timeout * 1E9) {
          return "TIMEOUT";
        }
      }
      List<Double> n = new ArrayList<>();
      for (List<Integer> metric : metrics) {
        n.add(reduceAccordingOper(metric, powers.get(i), opers.get(i)));
      }
      if (n.stream().anyMatch(d -> d.isInfinite() || d.isNaN())) {
        continue;
      }

      LeastSq result = minimalLeastSq(n, iterTimes, BigO.N);
      if (result.rms < leastRms) {
        leastRms = result.rms;
        closestPower = powers.get(i);
        closestOper = opers.get(i);
      }
    }
    return getBigOStringMultipleParams(metricNames, closestPower, closestOper);
  }
}
