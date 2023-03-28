#include "PMergeMe.hpp"

/**
 * @brief Insertion sort algorithm pour Vector.
 * 
 * @param arr Vector a trier.
 * @param start Index de debut.
 * @param end Index de fin.
 * 
 */
void insertion_sort_vector(std::vector<int> &arr, int start, int end)
{
    for (int i = start + 1; i <= end; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Fusion de deux sous-vecteurs.
 * 
 * @param arr Vecteur a fusionner.
 * @param start Index de debut.
 * @param mid Index du milieu.
 * @param end Index de fin.
 */
void merge_vector(std::vector<int> &arr, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<int> left(n1);
    std::vector<int> right(n2);

    for (int i = 0; i < n1; ++i) {
        left[i] = arr[start + i];
    }
    for (int i = 0; i < n2; ++i) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

/**
 * @brief Tri merge-insert sort pour Vector.
 * 
 * @param arr Vector a trier.
 * @param start Index de debut.
 * @param end Index de fin.
 * @param limit Limite de taille pour insertion sort.
 */
void merge_insert_sort_vector(std::vector<int> &arr, int start, int end, int limit) {
    if (start < end) {
        if (end - start + 1 <= limit) {
            insertion_sort_vector(arr, start, end);
        } else {
            int mid = (start + end) / 2;
            merge_insert_sort_vector(arr, start, mid, limit);
            merge_insert_sort_vector(arr, mid + 1, end, limit);
            merge_vector(arr, start, mid, end);
        }
    }
}

/**
 * @brief Insertion sort algorithm pour Deque.
 * 
 */
void insertion_sort_deque(std::deque<int> &arr, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= start && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Fusion de deux sous-deques.
 * 
 */
void merge_deque(std::deque<int> &arr, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::deque<int> left(n1);
    std::deque<int> right(n2);

    for (int i = 0; i < n1; ++i) {
        left[i] = arr[start + i];
    }
    for (int i = 0; i < n2; ++i) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1) {
        arr[k++] = left[i++];
    }

    while (j < n2) {
        arr[k++] = right[j++];
    }
}

/**
 * @brief Tri merge-insert sort pour Deque.
 * 
 * @param arr Deque a trier.
 * @param start Index de debut.
 * @param end Index de fin.
 * @param limit Limite de taille pour insertion sort.
 */
void merge_insert_sort_deque(std::deque<int> &arr, int start, int end, int limit) {
    if (start < end) {
        if (end - start + 1 <= limit) {
            insertion_sort_deque(arr, start, end);
        } else {
            int mid = (start + end) / 2;
            merge_insert_sort_deque(arr, start, mid, limit);
            merge_insert_sort_deque(arr, mid + 1, end, limit);
            merge_deque(arr, start, mid, end);
        }
    }
}