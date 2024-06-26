#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, N, M;
pair<long long, long long> sum[1501];
bool tp[1501];
bool bt[1501];
pair<long long, long long> tpSum[1501];
int cnt[1501];
bool prv[1501];
long long fib[50];
set<long long> isFib;
int yesFib[1501];
int noFib[1501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("fibosnek.in", "r", stdin);
    //freopen("fibosnek.out", "w", stdout);
    cin >> C >> N >> M;
    fib[0] = 1;
    fib[1] = 1;
    isFib.insert(1);
    for (int i = 2; i < 50; i++) {
        fib[i] = fib[i-1]+fib[i-2];
        isFib.insert(fib[i]);
    }
    isFib.insert(-(1LL<<60));
    isFib.insert((1LL<<60));
    int fibCnt = 0;
    long long ans = 0LL;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            long long cur;
            cin >> cur;
            long long val = cur;
            bool flag = false;
            if (isFib.find(cur) != isFib.end()) {
                fibCnt++;
                flag = true;
            }
            else {
                long long L = *(--isFib.upper_bound(cur));
                long long R = *isFib.upper_bound(cur);
                if (L == -(1LL<<60)) val = R;
                else if (R == (1LL<<60)) val = L;
                else {
                    if (abs(cur-L) <= abs(cur-R)) {
                        val = L;
                    }
                    else {
                        val = R;
                    }
                }
            }
            if (i == 1) tp[j] = flag;
            if (i == N) bt[j] = flag;
            if (flag) yesFib[j]++;
            else noFib[j]++;
            if (prv[j] && flag) {
                sum[j].se += val;
            }
            if (prv[j] && !flag) {
                sum[j].se += val;
            }
            if (!prv[j] && flag) {
                sum[j].fi = sum[j].se;
                sum[j].se = val;
            }
            if (!prv[j] && !flag) {
                sum[j].se = val;
            }
            if (!((flag == tp[j]) && yesFib[j] && noFib[j])) {
                if (flag == tp[j]) {
                    tpSum[j].fi += val;
                }
                else {
                    tpSum[j].se += val;
                }
            }
            ans = max(ans, sum[j].fi+sum[j].se);
            prv[j] = flag;
        }
    }
    for (int i = 1; i <= M; i++) {

    }
    if (C == 1) {
        cout << fibCnt << "\n";
    }
    else {
        cout << ans << "\n";
    }
}