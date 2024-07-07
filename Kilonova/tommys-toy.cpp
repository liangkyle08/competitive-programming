#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);

int N;
int X[500001];
int Y[500001];
int cost[1360];
int delta[1020];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        if (X[i] < Y[i]) {
            int len = Y[i] - X[i];
            int maxDist = (360 - len) / 2;
            delta[Y[i]+1]++;
            if (len % 2 == 0) {
                delta[Y[i]+maxDist+1] -= 2;
                delta[X[i]+361]++;
            }
            else {
                delta[Y[i]+maxDist+1]--;
                delta[Y[i]+maxDist+2]--;
                delta[X[i]+361]++;
            }
        }
        else {
            int len = 360 - X[i] + Y[i];
            int maxDist = (360 - len) / 2;
            delta[Y[i]+361]++;
            if (len % 2 == 0) {
                delta[Y[i]+maxDist+361] -= 2;
                delta[X[i]+361]++;
            }
            else {
                delta[Y[i]+maxDist+361]--;
                delta[Y[i]+maxDist+362]--;
                delta[X[i]+361]++;
            }
        }
    }
    long long sum = 0;
    long long cur = 0;
    for (int i = 0; i < 720; i++) {
        cur += delta[i];
        sum += cur;
        cost[i] = sum;
    }
    for (int i = 0; i < 360; i++) {
        cost[i] += cost[i+360];
    }
    int ans = INF;
    for (int i = 0; i < 360; i++) {
        ans = min(ans, cost[i]);
    }
    cout << ans << '\n';
}
