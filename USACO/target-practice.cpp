#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, C;
string s;
bool target[200005];
map<int, int> hit;
map<int, int> whenHit;
set<int> suffix[5];
set<int> buffer[5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> C;
    for (int i = 1; i <= T; i++) {
        int x;
        cin >> x;
        target[x+C] = true;
    }
    cin >> s;
    int pos = C;
    for (int i = 1; i <= C; i++) {
        if (s[i-1] == 'L') pos--;
        if (s[i-1] == 'R') pos++;
        if (s[i-1] == 'F') {
            if (target[pos] && hit.find(pos) == hit.end()) {
                hit[pos] = i;
                whenHit[i] = pos;
            }
        }
    }
    int ans = (int)hit.size();
    for (int i = C; i >= 1; i--) {
        if (whenHit.find(i) != whenHit.end()) {
            hit.erase(whenHit[i]);
            whenHit.erase(i);
            for (int j = 0; j < 5; j++) {
                if (buffer[j].find(pos) != buffer[j].end()) {
                    suffix[j].insert(pos);
                    buffer[j].erase(pos);
                }
            }
        }
        if (s[i-1] == 'L') pos++;
        if (s[i-1] == 'R') pos--;
        if (s[i-1] == 'L') {
            // LF
            bool flag = target[pos] && (hit.find(pos) == hit.end()) && (suffix[3].find(pos) == suffix[3].end());
            ans = max(ans, (int)whenHit.size()+flag+(int)suffix[3].size());
            // LR
            ans = max(ans, (int)whenHit.size()+(int)suffix[4].size());
        }
        if (s[i-1] == 'R') {
            // RF
            bool flag = target[pos] && (hit.find(pos) == hit.end()) && (suffix[1].find(pos) == suffix[1].end());
            ans = max(ans, (int)whenHit.size()+flag+(int)suffix[1].size());
            // RL
            ans = max(ans, (int)whenHit.size()+(int)suffix[0].size());
        }
        if (s[i-1] == 'F') {
            // FL
            ans = max(ans, (int)whenHit.size()+(int)suffix[1].size());
            // FR
            ans = max(ans, (int)whenHit.size()+(int)suffix[3].size());
        }
        if (s[i-1] == 'F') {
            for (int j = pos-2; j <= pos+2; j++) {
                if (j < 0 || j > 200000) continue;
                if (target[j]) {
                    if (hit.find(j) != hit.end()) {
                        buffer[j-pos+2].insert(j);
                    }
                    else {
                        suffix[j-pos+2].insert(j);
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}