#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long V;
string M;
long long H[500001];
long long diff[500001];
long long pSum[500001];
int ans[500001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> V;
    long long startVal = (V*V+1)/2;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    for (int i = 1; i < N; i++) {
        if (H[i] > H[i+1]) {
            diff[i+1] = 10*(H[i]-H[i+1]);
        }
        else {
            diff[i+1] = -10*(H[i+1]-H[i]);
        }
        pSum[i+1] = pSum[i]+diff[i+1];
    }
    stack<int> s;
    for (int i = 1; i <= N; i++) {
        while (!s.empty() && startVal+pSum[i]-pSum[s.top()] < 0) {
            ans[s.top()] = i-1;
            s.pop();

        }
        s.push(i);
    }
    while (!s.empty()) {
        ans[s.top()] = N;
        s.pop();
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}
