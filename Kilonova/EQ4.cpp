#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C;
long long A, B, E;
long long pow10[18];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("eq4.in", "r", stdin);
    freopen("eq4.out", "w", stdout);
    pow10[0] = 1LL;
    for (int i = 1; i < 18; i++) {
        pow10[i] = pow10[i-1]*10LL;
    }
    cin >> C >> s >> A >> B >> E;
    vector<long long> val(5);
    map<char, int> key = {
            {'x', 0},
            {'y', 1},
            {'z', 2},
            {'t', 3},
            {'r', 4}
    };
    deque<char> q;
    for (int i = (int)s.size()-1; i >= 0; i--) {
        if (s[i] == '+' || s[i] == '-') {
            long long sign = (s[i] == '+') ? 1LL : -1LL;
            char curVal = 'r';
            if (!q.empty() && isalpha(q.front())) {
                curVal = q.front();
                q.pop_front();
            }
            if (q.empty()) val[key[curVal]] += sign;
            while (!q.empty()) {
                val[key[curVal]] += sign*(long long)(q.back()-'0')*pow10[(int)q.size()-1];
                q.pop_back();
            }
        }
        else {
            q.push_back(s[i]);
        }
    }
    if (C == 1) {
        long long ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += val[i];
        }
        cout << ans << "\n";
    }
    else {
        long long ans = 0LL;
        vector<long long> cnt;
        for (long long x = A; x <= B; x++) {
            for (long long y = A; y <= B; y++) {
                cnt.push_back(val[0]*x+val[1]*y);
            }
        }
        sort(cnt.begin(), cnt.end());
        vector<long long> cnt2;
        for (long long z = A; z <= B; z++) {
            for (long long t = A; t <= B; t++) {
                long long diff = E-(val[2]*z+val[3]*t)-val[4];
                cnt2.push_back(diff);
            }
        }
        sort(cnt2.begin(), cnt2.end());
        int curInd = 0;
        int curCnt = 1;
        int len = (int)cnt.size();
        for (int i = 0; i < len; i++) {
            while (cnt2[curInd] < cnt[i]) {
                curInd++;
                curCnt = 1;
                while (curInd < len && cnt2[curInd] == cnt2[curInd+1]) {
                    curInd++;
                    curCnt++;
                }
            }
            while (curInd < len && cnt2[curInd] == cnt2[curInd+1]) {
                curInd++;
                curCnt++;
            }
            if (curInd >= len) break;
            if (cnt2[curInd] == cnt[i]) {
                ans += curCnt;
            }
        }
        cout << ans << "\n";
    }
}