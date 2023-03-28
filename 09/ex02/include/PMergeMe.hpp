#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>

void insertion_sort_deque(std::deque<int> &arr, int start, int end);
void merge_deque(std::deque<int> &arr, int start, int mid, int end);
void merge_insert_sort_deque(std::deque<int> &arr, int start, int end, int limit);

void insertion_sort_vector(std::vector<int> &arr, int start, int end);
void merge_vector(std::vector<int> &arr, int start, int mid, int end);
void merge_insert_sort_vector(std::vector<int> &arr, int start, int end, int limit);

#endif