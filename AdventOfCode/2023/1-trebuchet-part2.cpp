#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T = 1000;
string numList[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

bool check(string A, string B) {
    if (A.size() != B.size()) return false;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int total = 0;
    while (T--) {
        string s;
        cin >> s;
        int i = 0;
        while (i < s.size()) {
            if (0 <= s[i]-'0' && s[i]-'0' <= 9) {
                total += 10*(s[i]-'0');
                break;
            }
            bool flag = false;
            for (int ind = 0; ind < 9; ind++) {
                string num = numList[ind];
                if (check(num, s.substr(i, min((int)num.size(), (int)s.size() - i)))) {
                    total += 10*(ind+1);
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            i++;
        }
        i = s.size()-1;
        while (i >= 0) {
            if (0 <= s[i]-'0' && s[i]-'0' <= 9) {
                total += s[i]-'0';
                break;
            }
            bool flag = false;
            for (int ind = 0; ind < 9; ind++) {
                string num = numList[ind];
                if (check(num, s.substr(max(i - ((int)num.size() - 1), 0), min((int)num.size(), (int)s.size())))) {
                    total += ind+1;
                    flag = true;
                    break;
                }
            }
            if (flag) break;
            i--;
        }
    }
    cout << total << "\n";
}
