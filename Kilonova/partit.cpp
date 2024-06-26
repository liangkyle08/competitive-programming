#include <bits/stdc++.h>
using namespace std;

int T, N;

void solve1() {
    long long K;
    cin >> K;
    vector<long long> arr;
    while (N > 0) {
        int val = 0;
        long long lower = 0LL;
        long long upper = 0LL;
        while (K > upper) {
            val++;
            lower = upper+1LL;
            if (N-val-1 > 60) {
                upper = (1LL << 60);
                continue;
            }
            upper += (1LL << (max(N-val-1, 0)));
        }
        arr.push_back(val);
        K = K-lower+1LL;
        N -= val;
    }
    for (auto v: arr) {
        cout << v << " ";
    } cout << "\n";
}

void solve2() {
    long long ans = 1LL;
    while (N > 0) {
        int val;
        cin >> val;
        int val2 = val;
        while (val > 1) {
            ans += (1LL << (max(N-val, 0)));
            val--;
        }
        N -= val2;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("partit.in", "r", stdin);
    freopen("partit.out", "w", stdout);
    cin >> T >> N;
    if (T == 1) {
        solve1();
    }
    else {
        solve2();
    }
}
