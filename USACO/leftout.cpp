#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
bool arr[1001][1001]; // 'L' is false, 'R' is true
int cnt[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("leftout.in", "r", stdin);
    freopen("leftout.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            arr[i][j] = (s[j-1] == 'R');
            if (arr[i][j]) cnt[i]++;
        }
    }
    // Row
    int rowInd = -1;
    int rowCnt = 0;
    for (int i = 2; i <= N; i++) {
        bool flag = true;
        for (int j = 1; j <= N; j++) {
            if (arr[1][j] == arr[i][j]) continue;
            flag = false;
            break;
        }
        if (flag) continue;
        flag = true;
        for (int j = 1; j <= N; j++) {
            if (arr[1][j] == !arr[i][j]) continue;
            flag = false;
            break;
        }
        if (flag) continue;
        rowInd = i;
        rowCnt++;
    }
    if (rowCnt == N-1) rowInd = 1;
    // Row
    int colInd = -1;
    int colCnt = 0;
    for (int j = 2; j <= N; j++) {
        bool flag = true;
        for (int i = 1; i <= N; i++) {
            if (arr[i][1] == arr[i][j]) continue;
            flag = false;
            break;
        }
        if (flag) continue;
        flag = true;
        for (int i = 1; i <= N; i++) {
            if (arr[i][1] == !arr[i][j]) continue;
            flag = false;
            break;
        }
        if (flag) continue;
        colInd = j;
        colCnt++;
    }
    if (colCnt == N-1) colInd = 1;
    if ((rowCnt != 1 && rowCnt != N-1) || (colCnt != 1 && colCnt != N-1)) {
        cout << -1 << "\n";
    }
    else {
        cout << rowInd << " " << colInd << "\n";
    }

}
