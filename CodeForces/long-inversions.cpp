#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
string s;
bool A[5001];

bool check(int K) {
    vector<bool> left(N+5), right(N+5);
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (left[i]) cnt--;
        if ((cnt % 2 == 1) == A[i]) {
            if (i+K-1 > N) break;
            cnt++;
            right[i] = true;
            left[i+K] = true;
        }
    }
    cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (left[i]) cnt--;
        if (right[i]) cnt++;
        if ((cnt % 2 == 1) == A[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> s;
        for (int i = 1; i <= N; i++) {
            A[i] = (s[i-1] == '1');
        }
        int ans = 0;
        for (int i = N; i >= 1; i--) {
            if (check(i)) {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
}
