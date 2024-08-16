#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

string s, t;
bool A[(int)1e5 + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    int numZero = 0;
    int numOnes = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        A[i] = s[i] - '0';
        if (!A[i]) numZero++;
        if (A[i]) numOnes++;
    }
    if (numZero == 0 || numOnes == 0) {
        if (numOnes > 0 && (int)t.size() % numOnes != 0) {
            cout << 0 << "\n";
            return 0;
        }
        if (numZero > 0 && (int)t.size() % numZero != 0) {
            cout << 0 << "\n";
            return 0;
        }
        int len = (int)t.size() / (numOnes > 0 ? numOnes : numZero);
        string val = t.substr(0, len);
        int i = 0;
        int j = 0;
        while (i < (int)s.size()) {
            if (val != t.substr(j, len)) {
                cout << 0 << "\n";
                return 0;
            }
            j += len;
            i++;
        }
        cout << 1 << "\n";
        return 0;
    }
    int ans = 0;
    for (int len1 = 1; len1 <= (int)t.size(); len1++) {
        if (((int)t.size() - len1 * numZero) % numOnes != 0) continue;
        int len2 = ((int)t.size() - len1 * numZero) / numOnes;
        if (len2 <= 0) continue;
        string val[2] = {"#", "#"};
        int i = 0;
        int j = 0;
        bool flag = false;
        while (i < (int)s.size()) {
            if (val[A[i]] == "#") {
                val[A[i]] = t.substr(j, (A[i] ? len2 : len1));
            }
            else if (val[A[i]] != t.substr(j, (A[i] ? len2 : len1))) {
                flag = true;
                break;
            }
            j += (A[i] ? len2 : len1);
            i++;
        }
        if (flag || val[0] == val[1]) continue;
        ans++;
    }
    cout << ans << "\n";
}
