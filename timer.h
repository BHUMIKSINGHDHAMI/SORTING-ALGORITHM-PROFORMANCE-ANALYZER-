#ifndef TIMER_H
#define TIMER_H

#include <vector>
#include "metrics.h"

double measureTime(void (*fn)(std::vector<int>&, Metrics&), std::vector<int>& arr,
Metrics& m);
#endif