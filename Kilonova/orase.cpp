#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, X;
int dist[50001];
int speed[50001];

double getTime(pair<int, int> pi) {
    return ((double)pi.fi)/((double)pi.se);
}

class Compare {
public:
    bool operator()(pair<int, int> A, pair<int, int> B) {
        return getTime(A) < getTime(B);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("orase.in", "r", stdin);
    freopen("orase.out", "w", stdout);
    cin >> T >> N >> X;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    for (int i = 1; i <= N; i++) {
        cin >> dist[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> speed[i];
    }
    for (int i = 1; i <= N; i++) {
        pq.push({dist[i], speed[i]});
    }
    while (X--) {
        pair<int, int> pi = pq.top();
        pq.pop();
        pq.push({pi.fi, pi.se+1});
    }
    double ans = 0.0;
    while (!pq.empty()) {
        pair<int, int> pi = pq.top();
        pq.pop();
        ans += getTime(pi);
    }
    cout << (int)ans << "\n";
}
