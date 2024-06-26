#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
long long x1;

void solve() {
    cin >> N >> x1;
    vector<pair<long long, long long>> leftCoord, upperRightCoord, lowerRightCoord;
    for (int i = 1; i <= N; i++) {
        long long y1, y2, x2;
        cin >> y1 >> y2 >> x2;
        leftCoord.push_back({x1, y1});
        leftCoord.push_back({x1, y2});
        lowerRightCoord.push_back({x2, y1});
        upperRightCoord.push_back({x2, y2});
    }
    sort(leftCoord.begin(), leftCoord.end());
    sort(lowerRightCoord.begin(), lowerRightCoord.end());
    sort(upperRightCoord.begin(), upperRightCoord.end());
    vector<long long> pos, neg;
    for (int i = 1; i <= 4*N; i++) {
        long long slope;
        cin >> slope;
        if (slope > 0) {
            pos.push_back(slope);
        }
        else {
            neg.push_back(slope);
        }
    }
    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());
    if ((int)pos.size() < N || (int)neg.size() < N) {
        cout << -1 << "\n";
        return;
    }
    vector<int> smallPos, smallNeg, large;
    for (int i = 0; i < N; i++) {
        smallPos.push_back(pos.back());
        smallNeg.push_back(neg.back());
        pos.pop_back();
        neg.pop_back();
    }
    while (!pos.empty()) {
        large.push_back(pos.back());
        pos.pop_back();
    }
    while (!neg.empty()) {
        large.push_back(neg.back());
        neg.pop_back();
    }
    sort(smallPos.begin(), smallPos.end());
    sort(smallNeg.begin(), smallNeg.end());
    sort(large.begin(), large.end());
    long long upper = -(1LL<<60);
    long long lower = (1LL<<60);
    for (int i = 0; i < 2*N; i++) {
        long long x = leftCoord[i].fi;
        long long y = leftCoord[i].se;
        long long m = large[i];
        long long yInt = y-m*x;
        upper = max(upper, yInt);
        lower = min(lower, yInt);
    }
    // Binary Search
    long long low = (1LL<<60);
    long long high = -(1LL<<60);
    for (auto [x, y]: upperRightCoord) {
         high = max(high, y-smallNeg.front()*x); // Steepest
         low = min(low, y-smallNeg.back()*x); // Most Level
    }
    while (low < high) {
        long long mid = low+(high-low)/2;
        vector<long long> slopes;
        for (auto [x, y]: upperRightCoord) {
            slopes.push_back((y-mid)/x);
        }
        sort(slopes.begin(), slopes.end());
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (smallNeg[i] < slopes[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    upper = max(upper, low);
    low = (1LL<<60);
    high = -(1LL<<60);
    for (auto [x, y]: lowerRightCoord) {
        high = max(high, y-smallPos.front()*x); // Steepest
        low = min(low, y-smallPos.back()*x); // Most Level
    }
    while (low < high) {
        long long mid = low+(high-low+1)/2;
        vector<long long> slopes;
        for (auto [x, y]: lowerRightCoord) {
            slopes.push_back((y-mid)/x);
        }
        sort(slopes.begin(), slopes.end());
        bool flag = true;
        for (int i = 0; i < N; i++) {
            if (smallPos[i] > slopes[i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            low = mid;
        }
        else {
            high = mid-1;
        }
    }
    lower = min(lower, low);
    cout << upper-lower << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
