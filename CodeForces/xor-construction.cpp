#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int A[200001];
int B[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int maxPow = 32;
    for (int i = 0; i < 32; i++) {
        if ((1<<i) > N) {
            maxPow = i;
            break;
        }
    }
    for (int i = 2; i <= N; i++) {
        cin >> A[i];
    }
    vector<int> cnt(maxPow);
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < maxPow; j++) {
            bool flag = (B[i-1] & (1<<j));
            if (A[i] & (1<<j)) {
                B[i] += (1<<j)*(!flag);
            }
            else {
                B[i] += (1<<j)*flag;
            }
        }
        for (int j = 0; j < maxPow; j++) {
            if (B[i] & (1<<j)) {
                cnt[j]++;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < maxPow; j++) {
            if (cnt[j] > N/2) {
                if (B[i] & (1<<j)) {
                    B[i] -= (1<<j);
                }
                else {
                    B[i] += (1<<j);
                }
            }
        }
        cout << B[i] << " ";
    } cout << "\n";
}
