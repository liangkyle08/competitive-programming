#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> arr;
        int rem = K-1;
        for (int i = 0; i <= 31; i++) {
            if (rem-(1<<i) < 0) break;
            rem -= ((1 << i));
            arr.push_back((1 << i));
            //cout << "A: " << arr.back() << "\n";
        }
        if (rem > 0) arr.push_back(rem);
        int cur = K-1;
        int nxt = K+1;
        while (nxt <= N) {
            arr.push_back(nxt);
            cur += nxt;
            nxt = cur+1;
        }
        cout << (int)arr.size() << "\n";
        for (auto v: arr) {
            cout << v << " ";
        } cout << "\n";
    }
}
