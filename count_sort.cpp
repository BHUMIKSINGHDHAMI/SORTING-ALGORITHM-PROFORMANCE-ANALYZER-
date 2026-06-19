#include "count_sort.h"
#include <algorithm>
using namespace std;

void countSort(vector<int>& arr, Metrics &m) {
    if (arr.empty()) return;

    int n = arr.size();

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    int range = maxVal - minVal + 1;

    vector<int> count(range, 0);
    vector<int> output(n);

    // Count frequency
    for (int i = 0; i < n; i++)
        count[arr[i] - minVal]++;

    // Prefix sums
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    // Stable placement
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
        m.swaps++;        
    }

    arr = output;
}
