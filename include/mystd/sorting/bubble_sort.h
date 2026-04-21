#pragma once

#include <vector>

std::vector<int> bubble_sort_naive(const std::vector<int> &input);
std::vector<int> bubble_sort_shrink_inner_loop(const std::vector<int> &input);
std::vector<int> bubble_sort_early_exit(const std::vector<int> &input);
