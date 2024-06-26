#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, L;
long long K;
int arr[100001];

bool check(int X) {
    long long totalCost = 0;
    multiset<int> cost;
    for (int i = 1; i <= X; i++) {
        if (cost.empty()) {
            totalCost += (long long)max(0, X-arr[i]);
        }
        else {
            totalCost += (long long)max(0, max(0, X-arr[i]) - *(--cost.end()));
        }
        cost.insert(max(0, X-arr[i]));
        if ((int)cost.size() >= L) {
            cost.erase(cost.find(max(0, X-arr[i-L+1])));
        }
    }
    if (totalCost <= K) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K >> L;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1, greater<int>());
    int ans = 0;
    if (K == 0 || L == 0) {
        bool flag = true;
        for (int i = 1; i <= N; i++) {
            if (arr[i] < i) {
                ans = i-1;
                flag = false;
                break;
            }
        }
        if (flag) {
            ans = N;
        }
    }
    else {
        int high = N;
        int low = 1;
        while (low < high) {
            int mid = low+(high-low+1)/2;
            if (check(mid)) {
                low = mid;
            }
            else {
                high = mid-1;
            }
        }
        ans = low;
    }
    cout << ans << "\n";
}
