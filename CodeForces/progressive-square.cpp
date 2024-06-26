#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
long long C, D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> C >> D;
        multiset<long long> vals;
        long long A = (1LL<<60);
        for (int i = 1; i <= N*N; i++) {
            long long v;
            cin >> v;
            vals.insert(v);
            A = min(A, v);
        }
        bool flag = false;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                long long cur = A+i*C+j*D;
                if (vals.find(cur) == vals.end()) {
                    flag = true;
                    break;
                }
                else {
                    vals.erase(vals.find(cur));
                }
            }
            if (flag) break;
        }
        if (flag) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
}
