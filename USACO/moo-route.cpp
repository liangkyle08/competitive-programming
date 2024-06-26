#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int A[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int ind = 1;
    while (!(A[ind] == 0 && ind == 1)) {
        while (A[ind] > 0) {
            cout << "R";
            A[ind]--;
            ind++;
        }
        while (ind > 1 && (A[ind-1] > 1 || A[ind] == 0)) {
            cout << "L";
            ind--;
            A[ind]--;
        }
    } cout << "\n";
}
