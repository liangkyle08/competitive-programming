#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int N;
int H[MAX_N + 5];
int Left[MAX_N + 5];
int Right[MAX_N + 5];
int segTree[4 * MAX_N + 5];

void update(int node, int L, int R, int pos, int val) {
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
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

long long query(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return 0LL;
    }
    if (Lq <= L && R <= Rq) {
        return segTree[node];
    }
    int mid = (L + R) / 2;
    return query(2 * node, L, mid, Lq, Rq) + query(2 * node + 1, mid + 1, R, Lq, Rq);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    cin >> N;
    vector<pair<int, int>> comp;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
        comp.push_back({H[i], i});
    }
    sort(comp.begin(), comp.end());
    for (int i = 0; i < N; i++) {
        H[comp[i].se] = i + 1;
    }
    for (int i = 1; i <= N; i++) {
        update(1, 1, N, H[i], 1);
        Left[i] = query(1, 1, N, H[i] + 1, N);
    }
    for (int i = 1; i <= N; i++) {
        update(1, 1, N, H[i], 0);
    }
    for (int i = N; i >= 1; i--) {
        update(1, 1, N, H[i], 1);
        Right[i] = query(1, 1, N, H[i] + 1, N);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (max(Left[i], Right[i]) <= 2 * min(Left[i], Right[i])) continue;
        ans++;
    }
    cout << ans << "\n";
}
