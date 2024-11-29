#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 3e5;

int N, K;
long long T[MAX_N + 5];
vector<int> adjList[MAX_N + 5];
bool seen[MAX_N + 5];

void DFS(int node) {
    if (seen[node]) return;
    seen[node] = true;
    for (auto &child: adjList[node]) {
        DFS(child);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
    }
    priority_queue<long long> pq;
    unordered_map<long long, vector<int>> ind;
    for (int i = 1; i <= K; i++) {
        pq.push(-T[i]);
        if (!ind[T[i]].empty()) {
            int j = ind[T[i]].back();
            adjList[i].push_back(j);
            adjList[j].push_back(i);
        }
        ind[T[i]].push_back(i);
    }
    for (int i = K + 1; i <= N; i++) {
        long long curTime = -pq.top();
        int curInd = ind[curTime].back();
        pq.pop();
        ind[curTime].pop_back();
        if (ind[curTime].empty()) ind.erase(curTime);
        long long newTime = curTime + T[i];
        if (!ind[newTime].empty()) {
            int prvInd = ind[newTime].back();
            adjList[curInd].push_back(prvInd);
            adjList[prvInd].push_back(curInd);
        }
        pq.push(-newTime);
        ind[newTime].push_back(curInd);
    }
    long long finalTime = -pq.top();
    int root = ind[finalTime].back();
    DFS(root);
    cout << finalTime << "\n";
    for (int i = 1; i <= K; i++) {
        cout << seen[i];
    } cout << "\n";
}
