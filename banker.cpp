#include <iostream>
#include <vector>
#include "safe.hpp"

using namespace std;

bool isSafeState(const vector<vector<int>>& allocation,
                 const vector<vector<int>>& max,
                 const vector<int>& available,
                 vector<int>& safeSequence) {
    int n = allocation.size();    //num processes
    int m = available.size();     //num resource types

    vector<int> work = available;
    vector<bool> finish(n, false);
    vector<vector<int>> need(n, vector<int>(m));

    //need matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            need[i][j] = max[i][j] - allocation[i][j];

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; ++p) {
            if (!finish[p]) {
                bool canProceed = true;
                for (int j = 0; j < m; ++j) {
                    if (need[p][j] > work[j]) {
                        canProceed = false;
                        break;
                    }
                }
                if (canProceed) {
                    for (int k = 0; k < m; ++k)
                        work[k] += allocation[p][k];
                    safeSequence.push_back(p);
                    finish[p] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (!found)
            return false;  //system isn't in safe state
    }
    return true;
}

int main() {
    vector<vector<int>> allocation = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    vector<vector<int>> max = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    vector<int> available = {3, 3, 2};

    vector<int> safeSequence;

    if (isSafeState(allocation, max, available, safeSequence)) {
        cout << "System is in a safe state." << endl;
        cout << "Safe sequence is: ";
        for (int i = 0; i < safeSequence.size(); ++i)
            cout << "P" << safeSequence[i] << (i != safeSequence.size() - 1 ? " -> " : "\n");
    } else {
        cout << "System is NOT in a safe state." << endl;
    }

    return 0;
}

