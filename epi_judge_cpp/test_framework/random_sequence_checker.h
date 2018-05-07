
#pragma once

#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "test_failure.h"

int ComputeDeviationMultiplier(double allowed_false_negative, int num_rvs) {
  const double individual_rv_error = allowed_false_negative / num_rvs;
  std::array<double, 7> kErrorBounds = {
      1 - 0.682689492137086, 1 - 0.954499736103642, 1 - 0.997300203936740,
      1 - 0.999936657516334, 1 - 0.999999426696856, 1 - 0.999999998026825,
      1 - 0.999999999997440};

  return std::distance(
             begin(kErrorBounds),
             std::find_if(std::begin(kErrorBounds), std::end(kErrorBounds),
                          [individual_rv_error](double err) {
                            return err < individual_rv_error;
                          })) +
         1;
}

bool CheckFrequencies(const std::vector<int>& seq, int n,
                      double false_negative_tolerance) {
  const double avg = static_cast<double>(seq.size()) / n;
  const int k_indiv = ComputeDeviationMultiplier(false_negative_tolerance, n);
  const double p = 1.0 / n;
  const double sigma_indiv = std::sqrt(seq.size() * p * (1.0 - p));
  const double k_sigma_indiv = k_indiv * sigma_indiv;
  // To make our testing meaningful "sufficiently large", we need to have
  // enough testing data.
  if (seq.size() * p < 50 || seq.size() * (1 - p) < 50) {
    return true;
  }

  std::unordered_map<int, int> indiv_freqs;

  for (int a : seq) {
    ++indiv_freqs[a];
  }

  // Check that there are roughly std::size(seq)/n occurrences of key. By
  // roughly we mean the difference is less than k_sigma.
  return std::all_of(std::begin(indiv_freqs), std::end(indiv_freqs),
                     [avg, k_sigma_indiv](const auto& key_freq) {
                       return std::abs(avg - key_freq.second) <=
                              k_sigma_indiv;
                     });
}

bool CheckPairsFrequencies(const std::vector<int>& seq, int n,
                           double false_negative_tolerance) {
  std::vector<int> seq_pairs;

  for (int i = 1; i < seq.size(); ++i) {
    seq_pairs.push_back(seq[i - 1] * n + seq[i]);
  }

  return CheckFrequencies(seq_pairs, n * n, false_negative_tolerance);
}

bool CheckTriplesFrequencies(const std::vector<int>& seq, int n,
                             double false_negative_tolerance) {
  std::vector<int> seq_triples;

  for (int i = 2; i < seq.size(); ++i) {
    seq_triples.push_back(seq[i - 2] * n * n + seq[i - 1] * n + seq[i]);
  }

  return CheckFrequencies(seq_triples, n * n * n, false_negative_tolerance);
}

bool CheckBirthdaySpacings(const std::vector<int>& seq, int n) {
  const int expected_avg_repetition_length =
      static_cast<int>(std::ceil(std::sqrt(log(2) * 2.0 * n)));
  const int number_of_subarrays =
      seq.size() - expected_avg_repetition_length + 1;
  const int kMinNumberSubarrays = 1000;

  if (number_of_subarrays < kMinNumberSubarrays) {
    return true;  // Not enough subarrays for birthday spacing check
  }

  int number_of_subarrays_with_repetitions = 0;
  for (int i = 0; i < seq.size() - expected_avg_repetition_length; ++i) {
    std::unordered_set<int> seq_window(
        std::begin(seq) + i,
        std::begin(seq) + i + expected_avg_repetition_length);
    number_of_subarrays_with_repetitions +=
        (seq_window.size() < expected_avg_repetition_length);
  }

  const double kCountTolerance = 0.4;
  return kCountTolerance * number_of_subarrays <=
         number_of_subarrays_with_repetitions;
}

// seq is a sequence of integers, which should be in the range [0,n-1]. We
// assume n << std::size(seq).
bool CheckSequenceIsUniformlyRandom(const std::vector<int>& seq, int n,
                                    double false_negative_tolerance) {
  return CheckFrequencies(seq, n, false_negative_tolerance) &&
         CheckPairsFrequencies(seq, n, false_negative_tolerance) &&
         CheckTriplesFrequencies(seq, n, false_negative_tolerance) &&
         CheckBirthdaySpacings(seq, n);
}

int BinomialCoefficient(int n, int k) {
  if (n < k) {
    return 0;
  }
  if (k == 0 || k == n) {
    return 1;
  }
  return BinomialCoefficient(n - 1, k - 1) + BinomialCoefficient(n - 1, k);
}

// Get the mth combination in lexicographical order from A (n elements) chosen
// k at a time.
std::vector<int> ComputeCombinationIdx(const std::vector<int>& A, int n,
                                       int k, int m) {
  std::vector<int> comb;
  int a = n, b = k, x = (BinomialCoefficient(n, k) - 1) - m;
  for (int i = 0; i < k; ++i) {
    --a;
    while (BinomialCoefficient(a, b) > x) {
      --a;
    }
    comb.emplace_back(A[n - 1 - a]);
    x -= BinomialCoefficient(a, b);
    --b;
  }
  return comb;
}

// Run func several times, and early return if it succeed; otherwise, throws
// TestFailure.
void RunFuncWithRetries(const std::function<bool()>& func) {
  const int kNumRuns = 5;
  // If any of the run succeed, we assume the algorithm is correct.
  for (int i = 0; i < kNumRuns; ++i) {
    if (func()) {
      return;
    }
  }
  throw TestFailure("Result is not a random permutation");
}
