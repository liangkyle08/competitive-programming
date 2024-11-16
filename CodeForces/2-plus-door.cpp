#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const uint32_t MAX_N = 1e5;
const uint32_t MAX_Q = 2e5;
const uint32_t MAX_A = 30;

uint32_t N, Q;
vector<pair<uint32_t, uint32_t>> adjList[MAX_Q + 5];

bool getBit(uint32_t &x, uint32_t &pos) { return (x >> pos) & 1; }

void makeOne(uint32_t &x, uint32_t &pos) { x |= (1 << pos); }

void makeNull(uint32_t &x, uint32_t &pos) { x &= (~(1 << pos)); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    while (Q--) {
        uint32_t a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});
    }
    vector<uint32_t> ans(N + 5, ~(1 << (MAX_A + 1)));
    for (uint32_t i = 0; i <= MAX_A; i++) {
        for (uint32_t u = 1; u <= N; u++) {
            for (auto &[v, c]: adjList[u]) {
                if (!getBit(c, i)) {
                     makeNull(ans[u], i);
                     continue;
                }
                if (!getBit(ans[u], i) && !getBit(ans[v], i)) {
                    cout << -1 << "\n";
                    return 0;
                }
            }
        }
        for (uint32_t u = 1; u <= N; u++) {
            if (getBit(ans[u], i)) {
                makeNull(ans[u], i);
                for (auto &[v, c]: adjList[u]) {
                    if (!getBit(ans[v], i) && getBit(c, i)) {
                        makeOne(ans[u], i);
                        break;
                    }
                }
            }
        }
    }
    for (uint32_t i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}
