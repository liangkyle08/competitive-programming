#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int P, Q;
int arr[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("multimi.in", "r", stdin);
    freopen("multimi.out", "w", stdout);
    cin >> P >> Q;
    if (P > Q) {
        cout << -1 << "\n";
        exit(0);
    }
    int cur = 1;
    for (int j = 1; j <= Q; j++) {
        for (int i = 1; i <= P; i++) {
            arr[i][j] = cur;
            cur++;
        }
    }
    for (int j = 1; j <= P; j++) {
        vector<int> curCol = {0};
        for (int i = 1; i <= P; i++) {
            curCol.push_back(arr[i][j]);
        }
        rotate(curCol.begin()+1, curCol.begin()+j, curCol.end());
        for (int i = 1; i <= P; i++) {
            arr[i][j] = curCol[i];
        }
    }
    for (int j = P+1; j <= Q; j += 2) {
        vector<int> curCol = {0};
        for (int i = 1; i <= P; i++) {
            curCol.push_back(arr[i][j]);
        }
        reverse(curCol.begin()+1, curCol.end());
        for (int i = 1; i <= P; i++) {
            arr[i][j] = curCol[i];
        }
    }
    for (int i = 1; i <= P; i++) {
        for (int j = 1; j <= Q; j++) {
            cout << arr[i][j] << " ";
        } cout << "\n";
    }
}
