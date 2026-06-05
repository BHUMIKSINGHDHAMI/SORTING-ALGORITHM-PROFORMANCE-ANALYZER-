#include <iostream>
#include <vector>
#include <string>
// #include <bits/stdc++.h>
#include "input_handler.h"
#include "data_generator.h"
#include "analyzer.h"
#include "colors.h"

using namespace std;

void printTitle() {
    COLOR_CYAN;
    cout << "====================================================\n";
    cout << "                                                    \n";
    cout << "   SORTING PERFORMANCE ANALYZER                    \n";
    cout << "                                                    \n";
    cout << "====================================================\n";
    COLOR_RESET;
}

int main() {
    printTitle();

    vector<int> arr;
    int method = getInputMethod();

    cout << "\n";
    COLOR_YELLOW;
    cout << "-----------------------------------------------------\n";
    COLOR_RESET;

    if (method == 1) {
        COLOR_GREEN;
        cout << "[OK] Data Generation Mode Selected\n";
        COLOR_RESET;
        int n = getArraySize();
        int type = getDataType();
        arr = generateData(n, type);
        COLOR_GREEN;
        cout << "[OK] Data generated successfully.\n";
        COLOR_RESET;
        COLOR_CYAN;
        cout << "\nGenerated Array (" << arr.size() << " elements):\n";
        COLOR_RESET;
        COLOR_YELLOW;
        cout << "[ ";
        for (size_t i = 0; i < arr.size() && i < 20; i++) {
            cout << arr[i] << " ";
        }
        if (arr.size() > 20) cout << "... ";
        cout << "]\n";
        COLOR_RESET;
    }
    else if (method == 2) {
        COLOR_GREEN;
        cout << "[OK] Manual Input Mode Selected\n";
        COLOR_RESET;
        arr = getManualArray();
        COLOR_GREEN;
        cout << "[OK] Array captured successfully.\n";
        COLOR_RESET;
        COLOR_CYAN;
        cout << "\nInput Array:\n";
        COLOR_RESET;
        COLOR_YELLOW;
        cout << "[ ";
        for (int x : arr) {
            cout << x << " ";
        }
        cout << "]\n";
        COLOR_RESET;
    }
    else {
        COLOR_RED;
        cout << "[ERROR] Invalid choice. Exiting...\n";
        COLOR_RESET;
        return 0;
    }

    cout << "\n";
    COLOR_YELLOW;
    cout << "-----------------------------------------------------\n";
    COLOR_RESET;

    vector<int> algos = getAlgorithmChoices();

    if (algos.empty()) {
        COLOR_RED;
        cout << "[ERROR] No algorithms selected. Exiting...\n";
        COLOR_RESET;
        return 0;
    }

    runAnalysis(arr, algos);

    cout << "\n";
    COLOR_MAGENTA;
    cout << "====================================================\n";
    cout << "                                                    \n";
    cout << "          ANALYSIS COMPLETE                         \n";
    cout << "                                                    \n";
    cout << "====================================================\n";
    COLOR_RESET;

    return 0;
}