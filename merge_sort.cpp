#include "merge_sort.h"
using namespace std;

void merge(vector<int>& arr, int l, int mIdx, int r, Metrics &met) {
    int n1 = mIdx - l + 1;
    int n2 = r - mIdx;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mIdx + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        met.comparisons++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
        met.swaps++;
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortHelper(vector<int>& arr, int l, int r, Metrics &m) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSortHelper(arr, l, mid, m);
        mergeSortHelper(arr, mid + 1, r, m);
        merge(arr, l, mid, r, m);
    }
}

void mergeSort(vector<int>& arr, Metrics &m) {
    mergeSortHelper(arr, 0, arr.size() - 1, m);
}