// #include <iostream>
// #include <vector>
// #include <iomanip> // for setprecision
// #include <string>
#include <bits/stdc++.h>

#include "analyzer.h"
#include "metrics.h"
#include "timer.h"
#include "colors.h"

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include "count_sort.h"

using namespace std;

struct AlgoResult {
    string name;
    double time;
    long long comparisons;
    long long swaps;
};

string getAlgoName(int id) {
    switch (id) {
        case 1: return "Bubble Sort";
        case 2: return "Selection Sort";
        case 3: return "Insertion Sort";
        case 4: return "Merge Sort";
        case 5: return "Quick Sort";
        case 6: return "Count Sort";
        default: return "Unknown";
    }
}

void runAnalysis(const vector<int>& arr,
                 const vector<int>& algos) {

    vector<AlgoResult> results;

    for (int id : algos) {
        vector<int> temp = arr;
        Metrics m;
        double t = 0;

        switch (id) {
            case 1:
                t = measureTime(bubbleSort, temp, m);
                break;
            case 2:
                t = measureTime(selectionSort, temp, m);
                break;
            case 3:
                t = measureTime(insertionSort, temp, m);
                break;
            case 4:
                t = measureTime(mergeSort, temp, m);
                break;
            case 5:
                t = measureTime(quickSort, temp, m);
                break;
            case 6:
                t = measureTime(countSort, temp, m);
                break;
            default:
                continue;
        }

        results.push_back({getAlgoName(id), t, m.comparisons, m.swaps});
    }

    // Print beautiful table header
    cout << "\n\n";
    COLOR_CYAN;
    cout << "=====================================================================\n";
    cout << "| " << setw(18) << left << "Algorithm" << " | "
         << setw(14) << left << "Time (ms)" << " | "
         << setw(14) << left << "Comparisons" << " | "
         << setw(14) << left << "Swaps" << " |\n";
    cout << "=====================================================================\n";
    COLOR_RESET;

    // Print rows with alternating colors
    for (size_t i = 0; i < results.size(); i++) {
        const AlgoResult& res = results[i];

        if (i % 2 == 0) {
            COLOR_GREEN;
        } else {
            COLOR_YELLOW;
        }

        cout << "| ";
        cout << setw(18) << left << res.name << " | ";
        cout << setw(14) << fixed << setprecision(4) << left << res.time << " | ";
        cout << setw(14) << left << res.comparisons << " | ";
        cout << setw(14) << left << res.swaps << " |";
        COLOR_RESET;
        cout << "\n";
    }

    // Print table footer
    COLOR_CYAN;
    cout << "=====================================================================\n";
    COLOR_RESET;

    // Print performance summary
    if (!results.empty()) {
        double minTime = results[0].time;
        double maxTime = results[0].time;
        int fastestIdx = 0, slowestIdx = 0;

        for (size_t i = 1; i < results.size(); i++) {
            if (results[i].time < minTime) {
                minTime = results[i].time;
                fastestIdx = i;
            }
            if (results[i].time > maxTime) {
                maxTime = results[i].time;
                slowestIdx = i;
            }
        }

        cout << "\n";
        COLOR_MAGENTA;
        cout << "--- PERFORMANCE SUMMARY ---\n";
        COLOR_RESET;
        COLOR_GREEN;
        cout << "FASTEST: ";
        COLOR_RESET;
        cout << results[fastestIdx].name
             << " (" << fixed << setprecision(4) << results[fastestIdx].time << " ms)\n";
        COLOR_RED;
        cout << "SLOWEST: ";
        COLOR_RESET;
        cout << results[slowestIdx].name
             << " (" << fixed << setprecision(4) << results[slowestIdx].time << " ms)\n";
        COLOR_YELLOW;
        cout << "DIFFERENCE: ";
        COLOR_RESET;
        cout << fixed << setprecision(4) << (maxTime - minTime) << " ms\n";
    }

    cout << "\n";
    COLOR_CYAN;
    cout << "=====================================================================\n";
    COLOR_RESET;
}