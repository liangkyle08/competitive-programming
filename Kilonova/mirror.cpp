#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, N, K;
int arr[100001];

void solve1() {
    queue<bool> q;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        bool flag = false;
        for (int j = 31; j >= 0; j--) {
            if (arr[i] & (1<<j)) {
                flag = true;
            }
            if (flag) {
                q.push(arr[i] & (1<<j));
            }
            if ((int)q.size() == K) {
                ans.push_back(0);
                for (int k = K-1; k >= 0; k--) {
                    ans.back() += q.front()*(1<<k);
                    q.pop();
                }
            }
        }
    }
    for (auto v: ans) {
        cout << v << " ";
    } cout << "\n";
}

int flip(int X, int curPos) {
    for (int i = curPos; i >= 0; i--) {
        if (X & (1<<i)) {
            X -= (1<<i);
        }
        else {
            X += (1<<i);
        }
    }
    return X;
}

void solve2() {
    for (int i = 1; i <= N; i++) {
        int curPos = -1;
        for (int j = 31; j >= 0; j--) {
            if (arr[i] & (1<<j)) {
                curPos = j;
                break;
            }
        }
        for (int j = 1; j <= K; j++) {
            while (arr[i] > 0 && curPos >= 0 && !(arr[i] & (1<<curPos))) {
                curPos--;
            }
            if (arr[i] > 0 && curPos >= 0) {
                arr[i] = flip(arr[i], curPos);
            }
        }
    }
    pair<int, int> ans = {1, 1};
    int maxDist = -1;
    int prev = 0;
    for (int j = 0; j <= 31; j++) {
        for (int i = 1; i <= N; i++) {
            if (arr[i] & (1<<j)) {
                if (!prev) {
                    prev = i;
                }
                if (i == N || !(arr[i+1] & (1<<j))) {
                    if (i-prev > maxDist) {
                        maxDist = i-prev;
                        ans = {prev, i};
                    }
                    if ((i-prev == maxDist) && (prev < ans.fi)) {
                        ans = {prev, i};
                    }
                    prev = 0;
                }
                continue;
            }
        }
    }
    cout << maxDist+1 << "\n";
    cout << ans.fi << " " << ans.se << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mirror.in", "r", stdin);
    freopen("mirror.out", "w", stdout);
    cin >> C >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    if (C == 1) {
        solve1();
    }
    else {
        solve2();
    }
}
