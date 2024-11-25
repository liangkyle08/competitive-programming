#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int N;
int A[MAX_N + 5];
vector<int> adjList[MAX_N + 5];
int fileCnt[MAX_N + 5];
int totalFile;
long long in[MAX_N + 5];
long long out[MAX_N + 5];

bool isFile(int x) {
    return adjList[x].size() == 1 && x != 1;
}

void DFS(int node, int parent) {
    if (isFile(node)) {
        fileCnt[node] = 1;
    }
    for (auto &child: adjList[node]) {
        if (child == parent) continue;
        DFS(child, node);
        fileCnt[node] += fileCnt[child];
        in[node] += in[child] + fileCnt[child] * (A[child] + !isFile(child));
    }
}

void DFS2(int node, int parent) {
    for (auto &child: adjList[node]) {
        if (child == parent) continue;
        long long overlap = (in[node] - in[child]) - ((A[child] + !isFile(child)) * fileCnt[child]);
        out[child] = overlap + out[node] + (3 * (totalFile - fileCnt[child]));
        DFS2(child, node);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    cin >> N;
    totalFile = 0;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        A[i] = (i == 1 ? 0 : (int)s.size());
        int M;
        cin >> M;
        totalFile += (M == 0);
        for (int j = 1; j <= M; j++) {
            int k;
            cin >> k;
            adjList[i].push_back(k);
            adjList[k].push_back(i);
        }
    }
    DFS(1, -1);
    DFS2(1, -1);
    long long ans = LL_INF;
    for (int i = 1; i <= N; i++) {
        ans = min(ans, in[i] + out[i]);
    }
    cout << ans << "\n";
}
