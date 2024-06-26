#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[101][101];
int sz[101];
bool pos = true;
vector<int> adjList[27];
int inDegree[27];

int main() {
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            arr[i][j] = 0;
        }
    }
    cin >> N;
    vector<pair<int, string>> order(N);
    for (int i = 0; i < N; i++) {
        cin >> order[i].se;
    }
    for (int i = 0; i < N; i++) {
        cin >> order[i].fi;
    }
    sort(order.begin(), order.end());
    for (int i = 1; i <= N; i++) {
        string s = order[i-1].se;
        sz[i] = (int)s.size();
        for (int j = 1; j <= sz[i]; j++) {
            arr[i][j] = s[j-1]-'a'+1;
        }
    }
    for (int j = 1; j <= 100; j++) {
        for (int i = 1; i < N; i++) {
            if (arr[i][j-1] != arr[i+1][j-1]) { // Already in order
                continue;
            }
            if (arr[i][j] == arr[i+1][j]) { // Must check next position
                continue;
            }
            if (arr[i][j] == 0) {
                continue;
            }
            if (arr[i+1][j] == 0) {
                pos = false;
                continue;
            }
            adjList[arr[i][j]].push_back(arr[i+1][j]);
            inDegree[arr[i+1][j]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= 26; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topOrder;
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topOrder.push_back(u);
        for (auto v: adjList[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
        cnt++;
    }
    if (cnt != 26) pos = false;
    if (pos) {
        cout << "DA\n";
        vector<char> ans(27, '*');
        int curChar = 'a';
        for (auto v: topOrder) {
            ans[v] = curChar;
            curChar++;
        }
        for (int i = 1; i <= 26; i++) {
            if (ans[i] == '*') {
                ans[i] = curChar;
                curChar++;
            }
        }
        for (int i = 1; i <= 26; i++) {
            cout << ans[i];
        } cout << "\n";
    }
    else {
        cout << "NE\n";
    }
}
