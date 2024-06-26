#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C;
long long N;

void solve1() {
    long long X = 0;
    long long Y = 0;
    for (int i = 0; i < 18; i++) {
        if (X+9*powl(10, i) > N) break;
        X += 9*powl(10, i);
    }
    Y = N-X;
    long long ans = 0;
    for (int i = 0; i < 18; i++) {
        ans += X % 10;
        ans += Y % 10;
        X /= 10;
        Y /= 10;
    }
    cout << ans << "\n";
}

void solve2() {
    long long X = 0;
    long long Y = 0;
    for (int i = 0; i < 18; i++) {
        bool flag = false;
        for (int j = 1; j <= 9; j++) {
            if (X+powl(10, i) > N) {
                flag = true;
                break;
            }
            X += powl(10, i);
        }
        if (flag) break;
    }
    Y = N-X;
    cout << max(X, Y) << " " << min(X, Y) << "\n";
}


void solve3() {
    long long X = 0;
    long long Y = 0;
    for (int i = 0; i < 18; i++) {
        bool flag = false;
        for (int j = 1; j <= 9; j++) {
            if (X+powl(10, i) > N) {
                flag = true;
                break;
            }
            X += powl(10, i);
        }
        if (flag) break;
    }
    Y = N-X;
    long long X2 = 0;
    long long Y2 = 0;
    for (int i = 0; i < 18; i++) {
        X2 += powl(10, i)*(X % 10);
        Y2 += powl(10, i)*(Y % 10);
        X /= 10;
        Y /= 10;
        swap(X, Y);
    }
    cout << max(X2, Y2) << " " << min(X2, Y2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("nxy.in", "r", stdin);
    freopen("nxy.out", "w", stdout);
    cin >> C >> N;
    if (C == 1) {
        solve1();
    }
    else if (C == 2) {
        solve2();
    }
    else {
        solve3();
    }
}
