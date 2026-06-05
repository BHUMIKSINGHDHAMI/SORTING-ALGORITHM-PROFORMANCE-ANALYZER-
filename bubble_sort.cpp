#include "bubble_sort.h"
using namespace std;

void bubbleSort(vector<int>& arr, Metrics& m) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++) {
            m.comparisons++;
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                m.swaps++;
            }
        }
}