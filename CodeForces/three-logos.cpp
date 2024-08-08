#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

pair<int, int> rect[3];
char ans[305][305];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 3; i++) {
        cin >> rect[i].fi >> rect[i].se;
    }
    bool flag = false;
    for (int i = 0; i < 6; i++) {
        if (flag) break;
        for (int j = 0; j < 6; j++) {
            if (flag) break;
            if ((i % 3) == (j % 3)) continue;
            for (int k = 0; k < 6; k++) {
                if (flag) break;
                if ((j % 3) == (k % 3) || (i % 3) == (k % 3)) continue;
                if (i >= 3) swap(rect[i % 3].fi, rect[i % 3].se);
                if (j >= 3) swap(rect[j % 3].fi, rect[j % 3].se);
                if (k >= 3) swap(rect[k % 3].fi, rect[k % 3].se);
                if (rect[i % 3].fi == rect[j % 3].fi) {
                    if (rect[j % 3].fi == rect[k % 3].fi
                        && rect[i % 3].se + rect[j % 3].se + rect[k % 3].se == rect[i % 3].fi) {
                        flag = true;
                        cout << rect[i % 3].fi << '\n';
                        for (int x = 0; x < rect[i % 3].se; x++) {
                            for (int y = 0; y < rect[i % 3].fi; y++) {
                                cout << (char)('A' + (i % 3));
                            } cout << '\n';
                        }
                        for (int x = 0; x < rect[j % 3].se; x++) {
                            for (int y = 0; y < rect[j % 3].fi; y++) {
                                cout << (char)('A' + (j % 3));
                            } cout << '\n';
                        }
                        for (int x = 0; x < rect[k % 3].se; x++) {
                            for (int y = 0; y < rect[k % 3].fi; y++) {
                                cout << (char)('A' + (k % 3));
                            } cout << '\n';
                        }
                    }
                    if (rect[i % 3].se + rect[j % 3].se == rect[k % 3].se
                        && rect[i % 3].fi + rect[k % 3].fi == rect[k % 3].se) {
                        flag = true;
                        cout << rect[k % 3].se << '\n';
                        for (int x = 0; x < rect[i % 3].se; x++) {
                            for (int y = 0; y < rect[i % 3].fi + rect[k % 3].fi; y++) {
                                cout << (char)('A' + ((y < rect[i % 3].fi ? i : k) % 3));
                            } cout << '\n';
                        }
                        for (int x = 0; x < rect[j % 3].se; x++) {
                            for (int y = 0; y < rect[j % 3].fi + rect[k % 3].fi; y++) {
                                cout << (char)('A' + ((y < rect[j % 3].fi ? j : k) % 3));
                            } cout << '\n';
                        }
                    }
                }
                if (i >= 3) swap(rect[i % 3].fi, rect[i % 3].se);
                if (j >= 3) swap(rect[j % 3].fi, rect[j % 3].se);
                if (k >= 3) swap(rect[k % 3].fi, rect[k % 3].se);
            }
        }
    }
    if (!flag) cout << -1 << '\n';
}
