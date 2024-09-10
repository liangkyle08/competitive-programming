#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

long long N, K;
long long A[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("copii.in", "r", stdin);
    freopen("copii.out", "w", stdout);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        A[i] = i;
    }
    long long cnt = 0;
    long long temp = 1;
    while (temp < N) {
        temp *= K;
        cnt++;
    }
    cout << cnt << "\n";
    map<int, int> freq;
    map<int, vector<int>> teams;
    for (int i = 1; i <= cnt; i++) {
        freq.clear();
        teams.clear();
        for (int j = 1; j <= N; j++) {
            if (freq.count(A[j] % K) == 0) {
                freq[A[j] % K]++;
            }
            teams[A[j] % K].push_back(j);
            A[j] /= K;
        }
        cout << (int)freq.size() << "\n";
        for (int j = 0; j < (int)freq.size(); j++) {
            cout << (int)teams[j].size() << " ";
            for (int k = 0; k < (int)teams[j].size(); k++) {
                cout << teams[j][k] << " ";
            } cout << "\n";
        }
    }
}