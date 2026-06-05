#include <iostream>
#include "input_handler.h"

using namespace std;

int getInputMethod() {
    int ch;
    cout << "1.AUTO GENERATE\n2. MANUAL INPUT\nChoice: ";
    cin >> ch;
    return ch;
}

int getArraySize() {
    int n;
    cout << "Array size: ";
    cin >> n;
    return n;
}

int getDataType() {
    int t;
    cout << "1.RANDOM\n2.SORTED\n3.REVERSE SORTED\nChoice: ";
    cin >> t;
    return t;
}

vector<int> getManualArray() {
    int n;
    cout << "Number of elements: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> a[i];
    return a;
}

vector<int> getAlgorithmChoices() {
    vector<int> c;
    int x;
    cout << "1.BUBBLE SORT\n2.SELECTION SORT\n3.INSERTION SORT\n4.MERGE SORT\n5.QUICK SORT\n6.COUNT SORT\n(press 0 to stop)\n";
    while (true) {
        cin >> x;
        if (x == 0) break;
        c.push_back(x);
    }
    return c;
}