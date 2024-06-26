#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int A[100001];
int B[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N;
    vector<pair<int, int>> arr;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        arr.push_back({A[i], i});
        arr.push_back({B[i], i});
    }
    sort(arr.begin(), arr.end());
    int L = 0;
    int R = 0;
    int cnt = 0;
    vector<int> freq(N+1);
    multiset<int> vals;
    int ans = (1<<30);
    while (L < (int)arr.size() && R < (int)arr.size()) {
        if (cnt < N) {
            int val = arr[R].fi;
            int ind = arr[R].se;
            if (freq[ind] == 0) cnt++;
            freq[ind]++;
            vals.insert(val);
            R++;
        }
        if (cnt == N) {
            int mx = *(--vals.end());
            int mn = *(vals.begin());
            int val = arr[L].fi;
            int ind = arr[L].se;
            ans = min(ans, mx-mn);
            if (freq[ind]-1 == 0) cnt--;
            vals.erase(vals.find(val));
            freq[ind]--;
            L++;
        }
    }
    cout << ans << "\n";
}
