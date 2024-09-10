#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int N;
int shell[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= 3; i++) {
        shell[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        int a, b, g;
        cin >> a >> b >> g;
        swap(shell[a], shell[b])
    }
}
