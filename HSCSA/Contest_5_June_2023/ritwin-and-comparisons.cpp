#include <bits/stdc++.h>
using namespace std;

int N, y;
string x;

int main() {
    cin >> N;
    int lowerBound = -1e9;
    int upperBound = 1e9;
    int curVal = INT_MAX;
    bool pos = true;
    set<int> skip;
    while (N--) {
        cin >> x >> y;
        if (x == ">") {
            lowerBound = max(lowerBound, y+1);
        }
        if (x == "<") {
            upperBound = min(upperBound, y-1);
        }
        if (x == ">=") {
            lowerBound = max(lowerBound, y);
        }
        if (x == "<=") {
            upperBound = min(upperBound, y);
        }
        if (x == "==") {
            if (curVal != INT_MAX) pos = false;
            curVal = y;
        }
        if (x == "!=") {
            skip.insert(y);
        }
        if (upperBound < lowerBound) {
            pos = false;
        }
        if (curVal != INT_MAX && (curVal < lowerBound || curVal > upperBound)) {
            pos = false;
        }
    }
    int ans = 0;
    if (pos) {
        if (curVal != INT_MAX) {
            ans = 1;
        }
        else {
            ans = upperBound - lowerBound + 1;
            for (auto v: skip) {
                if (lowerBound <= v && v <= upperBound) {
                    ans--;
                }
            }
        }
    }
    cout << ans << "\n";
}
