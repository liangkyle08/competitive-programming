#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
int A[1000005];
int B[1000005];
int C[1000005];

bool cmp(int X, int Y) {
    if ((A[X]-B[X]) == (A[Y]-B[Y])) {
        return A[X] < A[Y];
    }
    return (A[X]-B[X]) < (A[Y]-B[Y]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    map<int, int> freq;
    for (int i = 1; i <= M; i++) {
        cin >> C[i];
        freq[C[i]]++;
    }
    vector<int> oper(N+1);
    for (int i = 1; i <= N; i++) {
        oper[i] = i;
    }
    sort(oper.begin()+1, oper.end(), cmp);
    int prev = 0;
    long long cnt = 0;
    long long ans = 0;
    for (auto [cur, num]: freq) {
        int diff = cur - prev;
        for (int i = 1; i <= N; i++) {
            int diff2 = (((diff) - A[oper[i]]) / (A[oper[i]] - B[oper[i]]) + 1);
            if (diff < A[oper[i]]) diff2 = 0;
            cnt += 2 * diff2;
            diff -= (A[oper[i]] - B[oper[i]]) * diff2;
        }
        ans += cnt * num;
    }
    cout << ans << "\n";
}
