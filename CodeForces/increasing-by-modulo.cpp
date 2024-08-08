#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 3e5;

int N, M;
int A[MAX_N + 5];

bool check(int X) {
    vector<int> B(N + 5);
    for (int i = 1; i <= N; i++) {
        if ((A[i] + X >= M) && ((A[i] + X) % M >= B[i - 1])) {
            B[i] = B[i - 1];
            continue;
        }
        if (A[i] < B[i - 1] && A[i] + X >= B[i - 1]) {
            B[i] = B[i - 1];
            continue;
        }
        B[i] = A[i];
    }
    for (int i = 1; i <= N; i++) {
        if (B[i] >= B[i - 1]) continue;
        return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int low = 0;
    int high = M;
    while (low < high) {
        int mid = (low + high) / 2;
        if (check(mid)) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    cout << low << "\n";
}
