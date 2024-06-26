#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T = 1000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int total = 0;
    while (T--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (0 <= s[i]-'0' && s[i]-'0' <= 9) {
                total += 10*(s[i]-'0');
                break;
            }
        }
        for (int i = s.size()-1; i >= 0; i--) {
            if (0 <= s[i]-'0' && s[i]-'0' <= 9) {
                total += s[i]-'0';
                break;
            }
        }
    }
    cout << total << "\n";
}
