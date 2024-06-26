#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, X, Y;

void solve() {
    cin >> N >> X >> Y;
    vector<int> A(X);
    map<int, bool> seen;
    for (int i = 0; i < X; i++) {
        cin >> A[i];
        seen[A[i]] = true;
    }
    sort(A.begin(), A.end());
    int total = X-2;
    for (int i = 0; i < X; i++) {
        int left = A[i];
        int mid = (A[i]+1 > N) ? A[i]-N+1 : A[i]+1;
        int right = (A[i]+2 > N) ? A[i]-N+2 : A[i]+2;
        if (seen[left] && seen[right] && !seen[mid]) {
            total++;
        }
    }
    priority_queue<int> even, odd;
    map<int, vector<pair<int, int>>> edge;
    for (int i = 0; i < X; i++) {
        int dist;
        if (i == X-1) dist = N-A[i]+A[0];
        else dist = A[i+1]-A[i];
        //cout << A[i] << " " << dist << "\n";
        if (dist % 2 == 0) {
            even.push(dist);
            edge[dist].push_back({A[i], A[(i == X-1) ? 0 : i+1]});
        }
        else {
            //cout << "B: " << dist << "\n";
            odd.push(dist);
            edge[dist].push_back({A[i], A[(i == X-1) ? 0 : i+1]});
        }
    }
    while (Y > 0) {
        if (!even.empty() && even.top() > 2) {
            int left = edge[even.top()].back().fi;
            int right = edge[even.top()].back().se;
            edge[even.top()].pop_back();
            vector<int> val;
            if (right < left) {
                for (int i = left+2; i <= N+right-2; i += 2) {
                    val.push_back((i > N) ? i-N : i);
                }
            }
            else {
                for (int i = left+2; i <= right-2; i += 2) {
                    val.push_back(i);
                }
            }
            for (auto v: val) {
                if (Y == 0) break;
                total += 2;
                if (v == right-2) {
                    total++;
                }
                Y--;
            }
            continue;
        }
        if (!odd.empty() && odd.top() > 1) {
            int left = edge[odd.top()].back().fi;
            int right = edge[odd.top()].back().se;
            edge[odd.top()].pop_back();
            vector<int> val;
            if (right < left) {
                for (int i = left+2; i < N+right; i += 2) {
                    val.push_back((i > N) ? i-N : i);
                }
            }
            else {
                for (int i = left+2; i < right; i += 2) {
                    val.push_back(i);
                }
            }
            for (auto v: val) {
                if (Y == 0) break;
                total += 2;
                Y--;
            }
            continue;
        }
        break;
    }
    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
