#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, K;
int A[100001];

bool cmp(int X, int Y) {
    return A[X] < A[Y];
}

void solve() {
    cin >> N >> K;
    map<int, vector<int>> freq;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        freq[A[i] % K].push_back(i);
    }
    int oddFreq = 0;
    for (auto &[u, v]: freq) {
        if ((int)v.size() % 2 == 0) continue;
        oddFreq++;
    }
    if (oddFreq >= 2) {
        cout << -1 << "\n";
        return;
    }
    long long ans = 0;
    for (auto &[u, v]: freq) {
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < (int)v.size(); i+=2) {
            if (i == (int)v.size()-1) break;
            ans += A[v[i+1]]-A[v[i]];
        }
        long long temp = ans;
        if ((int)v.size() % 2 == 1) {
            for (int i = (int)v.size()-2; i >= 0; i--) {
                if (i % 2 == 0) {
                    temp -= (A[v[i+2]]-A[v[i]]);
                    temp += (A[v[i+2]]-A[v[i+1]]);
                }
                else {
                    temp -= (A[v[i]]-A[v[i-1]]);
                    temp += (A[v[i+1]]-A[v[i-1]]);
                }
                ans = min(ans, temp);
            }
        }
    }
    cout << ans/K << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
