#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int T, N, A, B;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> A >> B >> s;
        int a = 0;
        int b = 0;
        bool flag = false;
        for (int i = 0; i < 500; i++) {
            if (s[i % N] == 'N') b++;
            if (s[i % N] == 'S') b--;
            if (s[i % N] == 'E') a++;
            if (s[i % N] == 'W') a--;
            if (a == A && b == B) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }

}
