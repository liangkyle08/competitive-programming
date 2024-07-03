#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int X[500005];
int Y[500005];
int inRed[365];
int outRed[365];
int flip[365];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    long long cur = 0;
    int add = 0;
    int sub = 0;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        inRed[X[i]]++;
        outRed[Y[i]]++;
        int far = ((Y[i] + X[i]) / 2) % 360;
        if (X[i] > Y[i]) {
            far = (far + 180) % 360;
            flip[far]++;
        }
        else {
            flip[far]++;
            int rightDist = X[i];
            int leftDist = 360 - Y[i];
            cur += min(leftDist, rightDist);
            if (far <= 180) {
                sub++;
            }
            else {
                add++;
            }
        }
    }
    sub -= inRed[0];
    add -= flip[0];
    sub += flip[0];
    add += outRed[0];
    long long ans = cur;
    for (int i = 1; i <= 360; i++) {
        sub -= inRed[i];
        if (i <= 180) {
            add -= flip[i];
            sub += flip[i];
        }
        else {
            add += flip[i];
            sub -= flip[i];
        }
        cur += add;
        cur -= sub;
        ans = min(ans, cur);
        cout << i << " " << add << " " << sub << "\n";
        add += outRed[i];
    }
    cout << ans << "\n";
}
