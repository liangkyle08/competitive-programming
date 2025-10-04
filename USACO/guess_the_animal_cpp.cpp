#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
const int MAX_K = 10000;

int N;
int A[MAX_N + 5][MAX_K + 5];
map<string, int> key;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    cin >> N;
    string s;
    for (int i = 1; i <= N; i++) {
        cin >> s;
        int K;
        cin >> K;
        for (int j = 1; j <= K; j++) {
            cin >> s;
            if (key[s] == 0) {
                key[s] = (int)(key.size());
            }
            A[i][key[s]] = 1;
        }
    }
    int ans = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int cnt = 0;
            for (int k = 1; k <= MAX_K; k++) {
                cnt += (A[i][k] == 1) && (A[j][k] == 1);
            }
            ans = max(ans, cnt + 1);
        }
    }
    cout << ans << "\n";
}
