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
long long A[MAX_N + 5];
unordered_map<long long, vector<long long>> adjList;
set<long long> seen;

void DFS(long long node) {
    if (seen.find(node) != seen.end()) return;
    seen.insert(node);
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
    for (int i = 1; i <= K; i++) {
        pq.push(-T[i]);
        adjList[T[i]].push_back(0);
        A[i] = T[i];
    }
    for (int i = K + 1; i <= N; i++) {
        long long curTime = -pq.top();
        pq.pop();
        A[i] = curTime + T[i];
        adjList[A[i]].push_back(curTime);
        pq.push(-A[i]);
    }
    long long root = -pq.top();
    DFS(root);
    cout << root << "\n";
    for (int i = 1; i <= K; i++) {
        cout << (seen.find(A[i]) != seen.end());
    } cout << "\n";
}
