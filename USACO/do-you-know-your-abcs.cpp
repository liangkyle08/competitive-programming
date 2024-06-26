#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[7];

map<string, int> key = {
        {"A", 0},
        {"B", 1},
        {"C", 2},
        {"A+B", 3},
        {"A+C", 4},
        {"B+C", 5},
        {"A+B+C", 6},
};

bool op(string A, string B) {
    return (arr[key[A]] > 0 && arr[key[B]] > 0);
}

void solve() {
    cin >> N;
    for (int i = 0; i < 7; i++) {
        if (i < N) {
            cin >> arr[i];
        }
        else {
            arr[i] = 0;
        }
    }
    sort(arr, arr+7);
    set<array<int, 3>> ans;
    do {
        array<int, 7> curArr;
        for (int i = 0; i < 7; i++) {
            curArr[i] = arr[i];
        }
        // Find A
        if (curArr[0] == 0) {
            vector<pair<string, string>> pos = {{"B", "A+B"}, {"C", "A+C"}, {"B+C", "A+B+C"}};
            for (auto [u, v]: pos) {
                if (op(u, v)) curArr[0] = curArr[key[v]]-curArr[key[u]];
            }
        }
        // Find B
        if (curArr[1] == 0) {
            vector<pair<string, string>> pos = {{"A", "A+B"}, {"C", "B+C"}, {"A+C", "A+B+C"}};
            for (auto [u, v]: pos) {
                if (op(u, v)) curArr[1] = curArr[key[v]]-curArr[key[u]];
            }
        }
        // Find C
        if (curArr[2] == 0) {
            vector<pair<string, string>> pos = {{"A", "A+C"}, {"B", "B+C"}, {"A+B", "A+B+C"}};
            for (auto [u, v]: pos) {
                if (op(u, v)) curArr[2] = curArr[key[v]]-curArr[key[u]];
            }
        }
        // Find A+B
        if (curArr[3] == 0) {
            if (op("A", "B")) curArr[key["A+B"]] = curArr[key["A"]]+curArr[key["B"]];
            if (op("C", "A+B+C")) curArr[key["A+B"]] = curArr[key["A+B+C"]]-curArr[key["C"]];
        }
        // Find A+C
        if (curArr[4] == 0) {
            if (op("A", "C")) curArr[key["A+C"]] = curArr[key["A"]]+curArr[key["C"]];
            if (op("B", "A+B+C")) curArr[key["A+C"]] = curArr[key["A+B+C"]]-curArr[key["B"]];
        }
        // Find B+C
        if (curArr[5] == 0) {
            if (op("B", "C")) curArr[key["B+C"]] = curArr[key["B"]]+curArr[key["C"]];
            if (op("A", "A+B+C")) curArr[key["B+C"]] = curArr[key["A+B+C"]]-curArr[key["A"]];
        }
        // Find A+B+C
        if (curArr[6] == 0) {
            if (op("A", "B") and op("B", "C")) curArr[key["A+B+C"]] = curArr[key["A"]]+curArr[key["B"]]+curArr[key["C"]];
        }
        bool flag = true;
        for (int i = 0; i < 7; i++) {
            if (curArr[i] <= 0) flag = false;
        }
        if (curArr[key["A"]] > curArr[key["B"]]) flag = false;
        if (curArr[key["B"]] > curArr[key["C"]]) flag = false;
        if (curArr[key["A"]]+curArr[key["B"]] != curArr[key["A+B"]]) flag = false;
        if (curArr[key["A"]]+curArr[key["C"]] != curArr[key["A+C"]]) flag = false;
        if (curArr[key["B"]]+curArr[key["C"]] != curArr[key["B+C"]]) flag = false;
        if (curArr[key["A"]]+curArr[key["B"]]+curArr[key["C"]] != curArr[key["A+B+C"]]) flag = false;
        if (flag) {
            ans.insert({curArr[0], curArr[1], curArr[2]});

        }
        for (int i = 0; i < 7; i++) {
            cout << arr[i] << " ";
        } cout << "\n";
    } while (next_permutation(arr, arr+7));
    cout << (int)ans.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cout << "TESTCASE" << "\n";
        solve();
    }
}
