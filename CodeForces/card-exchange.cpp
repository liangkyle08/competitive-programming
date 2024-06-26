#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
int A[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        map<int, int> freq;
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            freq[A[i]]++;
        }
        vector<int> cnt;
        for (auto [u, v]: freq) {
            cnt.push_back(v);
        }
        sort(cnt.begin(), cnt.end(), greater<int>());
        int extra = 0;
        for (int i = 0; i < (int)cnt.size(); i++) {
            bool flag = false;
            while (cnt[i] > 0) {
                if (cnt[i] >= K) {
                    cnt[i] -= K;
                    extra += K-1;
                    continue;
                }
                if (cnt[i]+extra >= K) {
                    extra -= (K-cnt[i]);
                    cnt[i] = 0;
                    extra += K-1;
                    continue;
                }
                flag = true;
                break;
            }
            if (flag) break;
        }
        extra = min(extra, K-1);
        int ans = 0;
        for (auto v: cnt) ans += v;
        cout << ans+extra << "\n";
    }
}
