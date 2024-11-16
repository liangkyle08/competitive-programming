#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int N, K;
int A[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    map<vector<pair<int, int>>, int> cnt;
    int kCnt = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        vector<pair<int, int>> fact;
        for (int j = 2; j * j <= A[i]; j++) {
            if (A[i] == 1) break;
            while (A[i] % j == 0) {
                if (fact.empty() || fact.back().fi != j) {
                    fact.push_back({j, 0});
                }
                A[i] /= j;
                fact.back().se++;
                fact.back().se %= K;
            }
            if (!fact.empty() && fact.back().se == 0) fact.pop_back();
        }
        if (A[i] > 1) {
            fact.push_back({A[i], 1});
        }
        if (!fact.empty()) {
            cnt[fact]++;
        }
        else {
            kCnt++;
        }
    }
    long long total = 2 * (long long)kCnt * (long long)(kCnt - 1) / 2LL;
    for (auto &[fact, cnt1]: cnt) {
        vector<pair<int, int>> comp;
        for (auto &[prime, exp]: fact) {
            comp.push_back({prime, (K - exp) % K});
        }
        int cnt2 = cnt[comp];
        if (fact == comp) {
            total += (long long)cnt1 * ((long long)cnt2 - 1);
            continue;
        }
        total += (long long)cnt1 * (long long)cnt2;
    }
    total /= 2;
    cout << total << "\n";
}
