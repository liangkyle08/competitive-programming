#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long Q;
long long A[100001];
long long B[100001];
long long pSum[100001];
map<long long, int> seen;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> Q;
    vector<pair<long long, int>> diff(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> B[i] >> A[i];
        diff[i] = {B[i]-A[i], i};
        Q -= A[i];
    }
    sort(diff.begin()+1, diff.end(), greater<pair<int, int>>());
    vector<int> ind(N+1);
    for (int i = 1; i <= N; i++) {
        pSum[i] = pSum[i-1]+diff[i].fi;
        seen[diff[i].fi] = i;
        ind[diff[i].se] = i;
    }
    for (int i = 1; i <= N; i++) {
        int low = 0;
        int high = N;
        int j = ind[i];
        cout << "A: " << j << "\n";
        bool flag = false;
        while (low < high) {
            int mid = (low+high)/2;
            long long sum = pSum[mid];
            if (mid >= seen[diff[j].fi]) {
                sum -= (diff[j].fi);
                flag = true;
            }
            else {
                flag = false;
            }
            if (sum >= Q) {
                high = mid;
            }
            else {
                low = mid+1;
            }
        }
        if (low == N && (pSum[N]-diff[j].fi) < Q) {
            cout << -1 << "\n";
            continue;
        }
        cout << low-flag << "\n";
    }
}
