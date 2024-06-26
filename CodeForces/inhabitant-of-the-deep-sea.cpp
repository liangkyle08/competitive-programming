#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
long long K;
long long A[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        deque<long long> dq;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            dq.push_back(A[i]);
        }
        int ans = 0;
        while (!dq.empty() && K > 0) {
            if ((int)dq.size() == 1) {
                if (K >= dq.back()) {
                    K -= dq.back();
                    ans++;
                    dq.pop_back();
                }
                break;
            }
            if (dq.front() > dq.back() && K >= 2*dq.back()) {
                dq.front() -= dq.back();
                K -= 2*dq.back();
                ans++;
                dq.pop_back();
                continue;
            }
            if (dq.front() <= dq.back() && K >= 2*dq.front()-1) {
                dq.back() -= dq.front()-1;
                K -= 2*dq.front()-1;
                ans++;
                dq.pop_front();
                if ((int)dq.size() == 1 || K == 0) continue;
                dq.back()--;
                K--;
                if (dq.back() == 0) {
                    ans++;
                    dq.pop_back();
                }
                continue;
            }
            break;
        }
        cout << ans << "\n";
    }
}
