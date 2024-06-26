#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, N;
vector<string> arr;

void solve1() {
    return;
}

void solve2() {
    map<char, int> freq;
    for (auto v: arr) {
        cout << v << "\n";
    }
    /*N = str.size();
    for (int i = 0; i < N; i++) {
        freq[str[i]]++;
    }
    vector<int> cnt(N+1);
    for (char c = 'a'; c <= 'z'; c++) {
        for (int i = 1; i <= freq[c]; i++) {
            int cur = i;
            for (int j = 2; j <= freq[c]; j++) {
                while (cur % j == 0) {
                    cnt[j]++;
                    cur = cur / j;
                }
            }
        }
    }
    long long ans = 1;
    for (int i = 1; i <= N; i++) {
        int cur = i;
        for (int j = N; j >= 1; j--) {
            cout << j << " " << cnt[j] << "\n";
        }
    }*/
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("raganama.in", "r", stdin);
    //freopen("raganama.out", "w", stdout);
    cin >> C;
    string str;
    while (std::cin >> str) {
        cout << str << "\n";
        arr.push_back(str);
    }
    if (C == 1) {
        solve1();
    }
    else {
        solve2();
    }
}
