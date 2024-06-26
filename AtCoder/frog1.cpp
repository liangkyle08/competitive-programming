#include <bits/stdc++.h>
using namespace std;

int N;
int H[100001];
int DP[100001];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
        DP[i] = INT_MAX;
    }
    DP[1] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= min(i+2, N); j++) {
            if (DP[i] + abs(H[i]-H[j]) < DP[j]) {
                DP[j] = DP[i] + abs(H[i]-H[j]);
            }
        }

    }
    cout << DP[N] << "\n";
}
