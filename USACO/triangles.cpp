#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
pair<int, int> arr[100001];
vector<long long> xCoord[10001];
vector<long long> yCoord[10001];
map<int, int> xCompress;
map<int, int> yCompress;
int xLen;
int yLen;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    set<int> xSet;
    set<int> ySet;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].fi >> arr[i].se;
        arr[i].fi += 10000;
        arr[i].se += 10000;
        xSet.insert(arr[i].fi);
        ySet.insert(arr[i].se);
    }
    int ind = 0;
    for (auto v: xSet) {
        ind++;
        xCompress[v] = ind;
    }
    xLen = ind;
    ind = 0;
    for (auto v: ySet) {
        ind++;
        yCompress[v] = ind;
    }
    yLen = ind;
    for (int i = 1; i <= N; i++) {
        xCoord[xCompress[arr[i].fi]].push_back(arr[i].se);
        yCoord[yCompress[arr[i].se]].push_back(arr[i].fi);
    }
    for (int i = 1; i <= xLen; i++) {
        sort(xCoord[i].begin(), xCoord[i].end());
        for (int j = 1; j < (int)xCoord[i].size(); j++) {
            xCoord[i][j] += xCoord[i][j]+xCoord[i][j-1];
        }
    }
    for (int i = 1; i <= yLen; i++) {
        sort(yCoord[i].begin(), yCoord[i].end());
        for (int j = 1; j < (int)yCoord[i].size(); j++) {
            yCoord[i][j] += yCoord[i][j]+yCoord[i][j-1];
        }
    }
    for (int i = 1; i <= N; i++) {
        int u = xCompress[arr[i].fi];
        
        int len = (int)yCoord[u].size()-yCompress[arr[i].se]
    }
}
