#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

string s;
int N;
long long X;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> X;
    N = (int)s.size();
    int maxLen = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        //cout << "~~~~ " << c << " ~~~~\n";
        vector<pair<int, bool>> lens;
        int prev = 0;
        for (int i = 1; i < N; i++) {
            if (s[i] != c && s[i-1] == c) {
                lens.push_back({i-prev, true});
                //cout << i-prev << " " << c << "\n";
                prev = i;
            }
            if (s[i] == c && s[i-1] != c) {
                lens.push_back({i-prev, false});
                //cout << i-prev << " not " << c << "\n";
                prev = i;
            }
        }
        if (N-prev > 0) {
            if (s[N] == c) {
                lens.push_back({N-prev, true});
                //cout << N-prev << " " << c << "\n";
            }
            if (s[N] != c) {
                lens.push_back({N-prev, false});
                //cout << N-prev << " not " << c << "\n";
            }
        }
        deque<pair<int, int>> q;
        int curLen = 0;
        long long curCost = 0;
        for (auto [len, flag]: lens) {
            q.push_back({len, flag});
            curLen += len;
            if (!flag) { // doesn't equal c
                curCost += (1LL<<len);
            }
            while (curCost > X) {
                int len2 = q.front().fi;
                bool flag2 = q.front().se;
                q.pop_front();
                curLen -= len2;
                if (!flag2) {
                    curCost -= (1LL<<len);
                }
            }
            maxLen = max(maxLen, curLen);
        }
    }
    cout << maxLen << "\n";
}
