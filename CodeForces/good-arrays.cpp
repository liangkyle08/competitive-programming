#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int arr[100001];

void solve() {
    cin >> N;
    long long numOnes = 0;
    long long extra = 0;
    for (int i = 1; i <= N; i++) { // All numbers greater than one become one, all one's become twos or greater
        cin >> arr[i];
        if (arr[i] == 1) {
            numOnes++;
        }
        else {
            extra += (arr[i]-1);
        }
    }
    if (numOnes <= extra && N > 1) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
