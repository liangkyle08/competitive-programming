#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1000;

int N;
int A[MAX_N + 5][MAX_N + 5];
int len[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    N = 1000;
    for (int i = 1; i <= N; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        len[i] = 1;
        while (ss >> A[i][len[i]]) len[i]++;
        len[i]--;
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        bool cur = false;
        for (int j = 0; j <= len[i]; j++) {
            vector<int> arr;
            for (int k = 1; k <= len[i]; k++) {
                if (k == j) continue;
                arr.push_back(A[i][k]);
            }
            bool dec = false;
            bool inc = false;
            int mx = -INF;
            int mn = INF;
            for (int k = 0; k < (int)arr.size() - 1; k++) {
                dec |= arr[k + 1] < arr[k];
                inc |= arr[k + 1] > arr[k];
                mx = max(mx, abs(arr[k + 1] - arr[k]));
                mn = min(mn, abs(arr[k + 1] - arr[k]));
            }
            cur |= (dec ^ inc) && (mx <= 3) && (mn >= 1);
        }
        ans += cur;
    }
    cout << ans << "\n";
}
