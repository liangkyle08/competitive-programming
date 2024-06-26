#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
bool canTravel[1001][1001];
bool diamond[1001][1001];

struct Node {
    int x, y;
    int coverX, coverY;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T >> N >> M;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++) {
            if (s[j-1] == 'O') {
                canTravel[i][j] = true;
            }
            if (s[j-1] == 'D') {
                canTravel[i][j] = true;
                diamond[i][j] = true;
            }
        }
        queue<Node> q0, q1;

    }
}
