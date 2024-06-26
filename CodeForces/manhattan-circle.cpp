#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        int prev = -1;
        int x = 0;
        int y = 0;
        int r = 0;
        string l;
        string t;
        bool flag = true;
        for (int i = 1; i <= N; i++) {
            string s;
            cin >> s;
            int cur = 0;
            for (int j = 1; j <= M; j++) {
                if (s[j-1] == '#') cur++;
            }
            if (cur < prev && flag) {
                x = i-1;
                r = (prev + 1) / 2;
                l = t;
                flag = false;
            }
            if (i == N && flag) {
                x = i;
                r = (cur + 1) / 2;
                l = s;
                flag = false;
            }
            prev = cur;
            t = s;
        }
        int cnt = 0;
        for (int j = 1; j <= M; j++) {
            if (l[j-1] == '#') cnt++;
            if (cnt == r) {
                y = j;
                break;
            }
        }
        cout << x << " " << y << "\n";
    }
}
