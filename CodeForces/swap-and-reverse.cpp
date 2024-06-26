#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, K, N;
string s;

void solve() {
    cin >> N >> K >> s;
    if (K % 2 == 0) {
        vector<int> arr;
        for (int i = 0; i < N; i++) {
            arr.push_back(s[i]-'a'+1);
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < N; i++) {
            cout << char('a'+arr[i]-1);
        } cout << "\n";
    }
    else {
        vector<int> even, odd;
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                even.push_back(s[i]-'a'+1);
            }
            else {
                odd.push_back(s[i]-'a'+1);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                cout << char('a'+even[i/2]-1);
            }
            else {
                cout << char('a'+odd[i/2]-1);
            }
        } cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}


