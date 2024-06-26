#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long M;
string s;
bool dir[200005];
long long arr[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> M >> s;
    int shift = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] != s[N-1]) {
            shift = i;
            break;
        }
    }
    long long total = 0;
    for (int i = 1; i <= N; i++) {
        dir[((i-shift+N-1) % N) + 1] = (s[i-1] == 'R');
        cin >> arr[((i-shift+N-1) % N) + 1];
    }
    bool flag = true;
    for (int i = 1; i <= N; i++) {
        total += arr[i];
        if (dir[i] != dir[1]) flag = false;
    }
    if (flag) {
        cout << total << "\n";
        exit(0);
    }
    long long cur = 0LL;
    // Right
    for (int i = 1; i <= N; i++) {
        if (!dir[i]) continue;
        if (i == N || dir[i] != dir[i+1]) {
            total -= min(cur, M);
            cur = 0;
        }
        else {
            cur += arr[i];
        }
    }
    cur = 0LL;
    // Left
    for (int i = N; i >= 1; i--) {
        if (dir[i]) continue;
        if (i == 1 || dir[i] != dir[i-1]) {
            total -= min(cur, M);
            cur = 0;
        }
        else {
            cur += arr[i];
        }
    }
    cout << total << "\n";
}
