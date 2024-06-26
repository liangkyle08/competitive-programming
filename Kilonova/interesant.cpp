#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
string arr[201];

bool check(string A, string B) {
    int i = 0;
    int cnt = 0;
    for (int j = 0; j < (int)B.size(); j++) {
        while (i < (int)A.size()) {
            if (A[i] == B[j]) {
                i++;
                cnt++;
                break;
            }
            i++;
        }
    }
    return (cnt == (int)B.size());
}

int main() {
    freopen("interesant.in", "r", stdin);
    freopen("interesant.out", "w", stdout);
    cin >> T >> N;
    set<string> s;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[j].size() >= arr[i].size()) continue;
            if (check(arr[i], arr[j])) {
                if (s.find(arr[j]) == s.end()) continue;
                s.erase(arr[j]);
            }
        }
    }
    if (T == 1) {
        string ans = "";
        for (auto v: s) {
            if ((int)v.size() > (int)ans.size()) {
                ans = v;
            }
        }
        cout << ans << "\n";
    }
    else {
        cout << (int)s.size() << "\n";
        for (int i = 1; i <= N; i++) { // Same order as input
            if (s.find(arr[i]) != s.end()) {
                cout << arr[i] << "\n";
            }
        }
    }
}
