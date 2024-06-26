#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, M;
vector<int> arr;
vector<int> prefix;
int l, r;

int findZeros() {
    int low = l;
    int high = r;
    while (low < high) {
        int mid = (low+high)/2;
        if (prefix[mid]-prefix[l-1] > 0) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    return low;
}

int findOnes() {
    int low = l;
    int high = r;
    while (low < high) {
        int mid = (low+high+1)/2;
        if (prefix[r]-prefix[mid-1] < r-mid+1) {
            low = mid;
        }
        else {
            high = mid-1;
        }
    }
    return low;
}

void solve() {
    cin >> N >> M;
    arr.clear();
    arr.resize(N+1);
    prefix.clear();
    prefix.resize(N+1);
    string s;
    cin >> s;
    for (int i = 1; i <= N; i++) {
        arr[i] = (s[i-1] == '1');
    }
    for (int i = 1; i <= N; i++) {
        prefix[i] = arr[i]+prefix[i-1];
    }
    bool same = false;
    set<pair<int, int>> ans;
    while (M--) {
        cin >> l >> r;
        pair<int, int> newOper = {findZeros(), findOnes()};
        if (newOper.fi >= newOper.se) { // Same as original array
            same = true;
        }
        else {
            ans.insert(newOper);
        }
    }
    cout << (int)ans.size()+same << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
