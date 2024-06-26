#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, N;
int A[1000001];
int freq[10];
int pSum[1000001];
int L[10], R[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("secv9.in", "r", stdin);
    freopen("secv9.out", "w", stdout);
    cin >> C >> N;
    int total = 0;
    int sum = 0;
    int pos = 0;
    int ans1 = 0;
    long long ans2 = 0;
    vector<int> left(10, -1);
    vector<int> cnt(10);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        total += A[i];
        if (A[i] != 0) {
            while (pos < i) {
                sum += A[pos];
                cnt[sum % 9]++;
                if (cnt[sum % 9] == 1) {
                    left[sum % 9] = pos;
                }
                pos++;
            }
        }
        if (pos > 0 && cnt[total % 9]) {
            ans1 = max(ans1, i - left[total % 9]);
            ans2 += cnt[total % 9];
        }
    }
    if (C == 1) {
        cout << ans1 << "\n";
    }
    else {
        cout << ans2 << "\n";
    }
}
