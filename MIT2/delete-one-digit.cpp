#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
string s;
int arr[200];

void solve() {
    cin >> s;
    N = (int)s.size();
    int sum = 0;
    for (int i = 0; i < N; i++) {
        arr[i] = s[i]-'0';
        sum += arr[i];
    }
    if (arr[N-1] == 2)  { // Ends with "...2"
        cout << s << " " << 2 << "\n";
        return;
    }
    if (arr[N-2] == 2) { // Ends with "...21"
        cout << s.substr(0, N-1) << " " << 2 << "\n";
        return;
    }
    // Ends with "...11"
    bool flag = true;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 2) {
            flag = false;
            break;
        }
    }
    if (flag) { // String is all 1s, and no 2s
        if (N % 2 == 0) {
            cout << s << " " << 11 << "\n";
        }
        if (N % 2 == 1) {
            cout << s.substr(0, N-1) << " " << 11 << "\n";
        }
        return;
    }
    if (sum % 3 == 0) { // Divisible by 3
        cout << s << " " << 3 << "\n";
        return;
    }
    if (sum % 3 == 1) { // Remove a 1
        for (int i = 0; i < N; i++) {
            if (arr[i] == 1) {
                cout << s.substr(0, i)+s.substr(i+1, N-i) << " " << 3 << "\n";
                return;
            }
        }
    }
    if (sum % 3 == 2) { // Remove a 2
        for (int i = 0; i < N; i++) {
            if (arr[i] == 2) {
                cout << s.substr(0, i)+s.substr(i+1, N-i) << " " << 3 << "\n";
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> T;
    while (T--) {
        solve();
    }
}
