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
vector<int> ans[MAX_N + 5][20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("copii.in", "r", stdin);
    freopen("copii.out", "w", stdout);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        A[i] = i;
    }
    queue<array<int, 3>> seg;
    seg.push({1, N, 1});
    int maxDepth = 1;
    while (!seg.empty()) {
        int left = seg.front()[0];
        int right = seg.front()[1];
        int depth = seg.front()[2];
        seg.pop();
        if (left == right) continue;
        maxDepth = max(maxDepth, depth);
        int diff = max((int)round((float)(right - left + 1) / (float)K), 1);
        int cnt = 0;
        for (int i = left; i <= right && cnt < K; i += diff) {
            int j = min(right, i + diff - 1);
            cnt++;
            if (cnt == K) {
                j = right;
            }
            for (int k = i; k <= j; k++) {
                ans[depth][cnt].push_back(k);
            }
            if (left == right) continue;
            seg.push({i, j, depth + 1});
        }
    }
    cout << maxDepth << "\n";
    for (int i = 1; i <= maxDepth; i++) {
        int sz = 0;
        for (int j = 1; j < 20; j++) {
            if (ans[i][j].empty()) break;
            sz = j;
        }
        cout << sz << "\n";
        for (int j = 1; j <= sz; j++) {
            cout << (int)ans[i][j].size() << " ";
            for (auto v: ans[i][j]) {
                cout << v << " ";
            } cout << "\n";
        }
    }
}