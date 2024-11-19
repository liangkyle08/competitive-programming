#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e5;

int T, N;
long long B;
long long S[MAX_N + 5];
long long P[MAX_N + 5];

int getInd(long long height) {
    int low = 0;
    int high = N;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (S[mid] <= height) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}

void solve() {
    cin >> B >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
    }
    sort(S + 1, S + N + 1);
    for (int i = 1; i <= N; i++) {
        P[i] = P[i - 1] + S[i];
    }
    long long lowHeight = 0;
    long long highHeight = 1e13;
    while (lowHeight < highHeight) {
        long long midHeight = (lowHeight + highHeight) / 2;
        int ind = getInd(midHeight);
        long long cost = (P[N] - P[ind]) - ((long long)(N - ind) * (midHeight));
        if (cost <= B) {
            highHeight = midHeight;
        }
        else {
            lowHeight = midHeight + 1;
        }
    }
    int ind2 = getInd(lowHeight);
    long long danger = ((long long)ind2 * lowHeight) - (P[ind2] - P[0]);
    highHeight = 1e13;
    while (lowHeight < highHeight) {
        long long midHeight = (lowHeight + highHeight + 1) / 2;
        int ind = getInd(midHeight);
        long long cur = ((long long)ind * midHeight) - (P[ind] - P[0]);
        if (cur <= danger) {
            lowHeight = midHeight;
        }
        else {
            highHeight = midHeight - 1;
        }
    }
    cout << lowHeight << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
