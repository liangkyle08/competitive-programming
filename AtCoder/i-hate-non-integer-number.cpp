#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 998244353;

int N;
int arr[101];
long long DP[101][101][101][101]; // First "i" items, choose "j" items, divided by "div" gets remainder "rem"

long long add(int A, int B) {
    return (A+B) % MOD;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= 100; i++) {
        DP[0][0][i][0] = 1; // Zero items, divided by anything remainder is always 0
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            for (int div = 1; div <= 100; div++) {
                for (int rem = 0; rem < div; rem++) {
                    if (DP[i-1][j-1][div][rem]) {
                        int newRem = (rem+arr[i]) % div;
                        DP[i][j][div][newRem] = add(DP[i][j][div][newRem], DP[i-1][j-1][div][rem]); // Add current item
                        DP[i][j-1][div][rem] = add(DP[i][j-1][div][rem], DP[i-1][j-1][div][rem]); // Don't add current item
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int j = 1; j <= N; j++) {
        ans = add(ans, DP[N][j][j][0]);
    }
    cout << ans << "\n";
}
