#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 3e5;

int N;
int H[MAX_N + 5];
int B[MAX_N + 5];
long long DP[MAX_N + 5];
long long segTree[4 * MAX_N + 5]; // 4 times size of N

void update(int node, int L, int R, int pos, long long val) {
    if (L == R) {
        segTree[node] = val;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid) {
        update(2 * node, L, mid, pos, val);
    }
    else {
        update(2 * node + 1, mid + 1, R, pos, val);
    }
    segTree[node] = max(segTree[2 * node], segTree[2 * node + 1]);
}

long long query(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return -LL_INF;
    }
    if (Lq <= L && R <= Rq) {
        return segTree[node];
    }
    int mid = (L + R) / 2;
    return max(query(2 * node, L, mid, Lq, Rq), query(2 * node + 1, mid + 1, R, Lq, Rq));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    stack<int> s;
    update(0, 0, N, 0, 0);
    for (int i = 1; i <= N; i++) {
        while (!s.empty() && H[s.top()] > H[i]) {
            s.pop();
        }
        if (s.empty()) {
            DP[i] = max(query(1, 1, N, 1, i - 1) + B[i], (long long)B[i]);
        }
        else {
            DP[i] = max(query(1, 1, N, s.top(), i - 1) + B[i], DP[s.top()]);
        }
        update(1, 1, N, i, DP[i]);
        s.push(i);
    }
    cout << DP[N] << "\n";
}