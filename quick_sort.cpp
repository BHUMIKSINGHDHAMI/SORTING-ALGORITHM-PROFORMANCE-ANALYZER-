#include "quick_sort.h"
using namespace std;

int partitionQS(vector<int>& arr, int low, int high, Metrics &m) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        m.comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            m.swaps++;
        }
    }
    swap(arr[i + 1], arr[high]);
    m.swaps++;
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high, Metrics &m) {
    if (low < high) {
        int pi = partitionQS(arr, low, high, m);
        quickSortHelper(arr, low, pi - 1, m);
        quickSortHelper(arr, pi + 1, high, m);
    }
}

void quickSort(vector<int>& arr, Metrics &m) {
    quickSortHelper(arr, 0, arr.size() - 1, m);
}