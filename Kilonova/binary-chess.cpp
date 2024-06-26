#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int R, C, N;
int row[200001];
int col[200001];
unordered_map<int, vector<int>> row_freq;
unordered_map<int, vector<int>> col_freq;
unordered_map<int, vector<int>> diag1_freq;
unordered_map<int, vector<int>> diag2_freq;
vector<int> adjList[200001];
bool seen[200001];

void DFS(int u) {
    if (seen[u]) return;
    seen[u] = true;
    for (auto v: adjList[u]) {
        DFS(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C >> N;
    for (int i = 1; i <= N; i++) {
        cin >> row[i] >> col[i];
        row_freq[row[i]].push_back(i);
        col_freq[col[i]].push_back(i);
        diag1_freq[row[i]-col[i]].push_back(i);
        diag2_freq[(R-row[i]+1)-col[i]].push_back(i);
    }
    for (auto [t, arr]: row_freq) {
        for (int i = 0; i < arr.size()-1; i++) {
            adjList[arr[i]].push_back(arr[i+1]);
            adjList[arr[i+1]].push_back(arr[i]);
        }
    }
    for (auto [t, arr]: col_freq) {
        for (int i = 0; i < arr.size()-1; i++) {
            adjList[arr[i]].push_back(arr[i+1]);
            adjList[arr[i+1]].push_back(arr[i]);
        }
    }
    for (auto [t, arr]: diag1_freq) {
        for (int i = 0; i < arr.size()-1; i++) {
            adjList[arr[i]].push_back(arr[i+1]);
            adjList[arr[i+1]].push_back(arr[i]);
        }
    }
    for (auto [t, arr]: diag2_freq) {
        for (int i = 0; i < arr.size()-1; i++) {
            adjList[arr[i]].push_back(arr[i+1]);
            adjList[arr[i+1]].push_back(arr[i]);
        }
    }
    int numOfComps = 0;
    for (int i = 1; i <= N; i++) {
        if (!seen[i]) {
            numOfComps++;
            DFS(i);
        }
    }
    long long ans = 1;
    for (int i = 1; i <= numOfComps; i++) {
        ans = (ans*2) % MOD;
    }
    cout << ans << "\n";
}
