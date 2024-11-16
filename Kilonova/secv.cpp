#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e6;

int T, K, N, S;
int A[MAX_N + 5];
int P[MAX_N + 5];
int R[MAX_N + 5]; // Prefix sums of subarrays of size K

void solve1() {
    vector<int> s;
    int sum = 0;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        sum += A[i];
        s.push_back(A[i]);
        if ((int)s.size() > K) sum -= s[(int)s.size() - K - 1];
        while ((int)s.size() >= K && sum > S) {
            ans++;
            for (int j = 1; j <= K; j++) {
                if ((int)s.size() - K >= 1) sum += s[(int)s.size() - K - 1];
                sum -= s.back();
                s.pop_back();
            }
        }
    }
    cout << ans << "\n";
}

void solve2() {
    vector<bool> buffer(N + 5);
    deque<int> dq;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        while (!dq.empty() && R[dq.back()] <= R[i] && i <= N - K) {
            buffer[dq.back()] = true;
            dq.pop_back();
        }
        dq.push_back(i);
        if (i > K + 1 && !buffer[i - K]) {
            buffer[i - K - 1] = true;
            dq.pop_front();
        }
        if (R[dq.front()] - A[i] > S) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("secv.in", "r", stdin);
    freopen("secv.out", "w", stdout);
    cin >> T >> N >> K >> S;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        P[i] = P[i - 1] + A[i];
    }
    for (int i = 1; i <= N; i++) {
        R[i] = (i + K <= N ? P[i + K] - P[i - 1] : P[N] - P[i - 1]);
    }
    if (T == 1) {
        solve1();
    }
    else {
        solve2();
    }
}
