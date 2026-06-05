#include "insertion_sort.h"
using namespace std;

void insertionSort(vector<int>& arr, Metrics &m) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            m.comparisons++;
            arr[j + 1] = arr[j];
            m.swaps++;
            j--;
        }
        if (j >= 0) m.comparisons++;
        arr[j + 1] = key;
    }
}