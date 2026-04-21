#include "mystd/sorting/bubble_sort.h"

std::vector<int> bubble_sort_naive(const std::vector<int> &input) {
  std::vector<int> sorted(input);
  for (int i = 0; i < sorted.size(); i++) {
    for (int j = 1; j < sorted.size(); j++) {
      if (sorted[j - 1] > sorted[j]) {
        std::swap(sorted[j - 1], sorted[j]);
      }
    }
  }
  return sorted;
}

std::vector<int> bubble_sort_shrink_inner_loop(const std::vector<int> &input) {
  std::vector<int> sorted(input);
  int n = sorted.size();
  for (int i = 0; i < sorted.size(); i++) {
    for (int j = 1; j < n; j++) {
      if (sorted[j - 1] > sorted[j]) {
        std::swap(sorted[j - 1], sorted[j]);
      }
    }
    n--;
  }
  return sorted;
}

std::vector<int> bubble_sort_early_exit(const std::vector<int> &input) {
  std::vector<int> sorted(input);
  bool has_swapped = false;
  for (int i = 0; i < sorted.size(); i++) {
    for (int j = 1; j < sorted.size(); j++) {
      if (sorted[j - 1] > sorted[j]) {
        std::swap(sorted[j - 1], sorted[j]);
        has_swapped = true;
      }
    }
    if (has_swapped) {
      break;
    }
  }
  return sorted;
}
