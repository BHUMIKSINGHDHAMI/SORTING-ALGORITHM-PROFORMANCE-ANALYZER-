#include <chrono>
#include "timer.h"

using namespace std;
using namespace chrono;
//using ll=long long;
double measureTime(void (*fn)(vector<int>&, Metrics&),
                   vector<int>& arr,
                   Metrics& m) {
    auto s = high_resolution_clock::now();
    fn(arr, m);
    auto e = high_resolution_clock::now();
    return duration<double, milli>(e - s).count();
}