#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    long long maxFreq = 1LL;
    long long minFreq = N;
    vector<long long> freq(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
        maxFreq = max(maxFreq, freq[arr[i]]);
        minFreq = min(minFreq, freq[arr[i]]);
    }
    cout << maxFreq*minFreq << "\n";
}
