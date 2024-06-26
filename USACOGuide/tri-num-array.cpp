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
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    map<int, int> freq;
    int cnt = 0;
    int ans = 0;
    deque<int> dq;
    for (int i = 1; i <= N; i++) {
        if (freq[arr[i]] == 0) cnt++;
        freq[arr[i]]++;
        dq.push_back(arr[i]);
        while (!dq.empty() && cnt > 3) {
            if (freq[dq.front()] == 1) cnt--;
            freq[dq.front()]--;
            dq.pop_front();
        }
        ans = max(ans, (int)dq.size());
    }
    cout << ans << "\n";
}
