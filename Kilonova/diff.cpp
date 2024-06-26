#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
int arr[100001];
int pSum[100001];
pair<int, int> pos[100001], neg[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("diff.in", "r", stdin);
    freopen("diff.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] == 0) arr[i] = -1;
        pSum[i] = pSum[i-1]+arr[i];
    }
    vector<pair<int, int>> ans(M+1);
    int minInd = 0;
    int maxInd = 0;
    for (int i = 1; i <= N; i++) {
        if (pSum[i] < pSum[minInd]) minInd = i;
        if (pSum[i] > pSum[maxInd]) maxInd = i;
        int maxDiff = pSum[i]-pSum[maxInd];
        int minDiff = pSum[i]-pSum[minInd];
        if (i != maxInd) {
            if (maxDiff >= 0) {
                pos[maxDiff] = {maxInd+1, i};
            }
            else {
                neg[-maxDiff] = {maxInd+1, i};
            }
        }
        if (i != minInd) {
            if (minDiff >= 0) {
                pos[minDiff] = {minInd+1, i};
            }
            else {
                neg[-minDiff] = {minInd+1, i};
            }
        }
    }
    for (int i = 1; i <= M; i++) {
        int v;
        cin >> v;
        if (-100000 > v || v > 100000) {
            cout << -1 << "\n";
            continue;
        }
        if (v >= 0) {
            if (pos[v].fi != 0) {
                cout << pos[v].fi << " " << pos[v].se << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
        else {
            if (neg[-v].fi != 0) {
                cout << neg[-v].fi << " " << neg[-v].se << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }
}
