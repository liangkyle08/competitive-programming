#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int D;
int arr[3][3] = {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> D;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j]+(D-1) << " ";
        } cout << "\n";
    }

}
