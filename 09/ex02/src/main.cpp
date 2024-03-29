#include <iostream>
#include "PmergeMe.hpp"
#include <string>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <cstring>

/**
 * @brief Check if a string is a valid integer.
 * 
 * @param str 
 * @return true | false
 *
 */
bool is_valid_int(const std::string &str) {
    if (str.empty()) {
        return false;
    }
    for (size_t i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int    display_help(char *argv)
{
    std::cout << "Usage: " << argv << " [integers]" << std::endl;
    std::cout << "Example : " << argv << " 3 7 1 2" << std::endl << std::endl;
    std::cout << "⚠️ If arg>INT_MAX, arg will overflow ! ⚠️" << std::endl;
    return 1;
}

/**
 * @brief PMergeMe : Sort an array of integer using the merge insert sort algorithm.
 * The array is parsed from the command line in two containers : one is a vector of
 * integers, the other is a deque of integers.
 * 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv)
{
    int limit = 20;

    if (argc < 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        display_help(argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        return display_help(argv[0]);
    }

    std::vector<int> v;
    std::deque<int> d;

    for (int i = 1; i < argc; i++) {
        if (!is_valid_int(argv[i])) {
            std::cerr << "Error: Invalid argument : [" << argv[i] << "]." << std::endl;
            return 1;
        }
    }

    
    for (int i = 1; i < argc; i++) {
        v.push_back(atoi(argv[i]));
        d.push_back(atoi(argv[i]));
    }

    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] < 0) {
            std::cerr << "Error: Invalid number: [" << argv[i + 1] << "]." << std::endl;
            return 1;
        }
    }

    std::cout << "Before: ";

    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    const clock_t begin_time_vector = clock();
    merge_insert_sort_vector(v, 0, v.size() - 1, limit);
    float elapsed_ms_vector = float(clock() - begin_time_vector) / (CLOCKS_PER_SEC/1000);
    const clock_t begin_time_deque = clock();
    merge_insert_sort_deque(d, 0, d.size() - 1, limit);
    float elapsed_ms_deque = float(clock() - begin_time_deque) / (CLOCKS_PER_SEC/1000);

    std::cout << "After: ";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    std::cout << std::setprecision(6) << "Time to process a range of " << v.size() << " elements with std::vector : " << elapsed_ms_vector << "ms" << std::endl;
    std::cout << std::setprecision(6) << "Time to process a range of " << d.size() << " elements with std::deque : " << elapsed_ms_deque << "ms" << std::endl;

    return 0;    
}