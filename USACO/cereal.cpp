#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
pair<int, int> arr[100001];
int cereal[100001];
int pos[100001]; // 0, 1, 2
int ans[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cereal.in", "r", stdin);
    freopen("cereal.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].fi >> arr[i].se;
    }
    int cnt = 0;
    for (int i = N; i >= 1; i--) {
        cnt++;
        pos[i] = 1;
        int nextCow = cereal[arr[i].fi];
        cereal[arr[i].fi] = i;
        while (nextCow != 0) {
            if (pos[nextCow] == 2) {
                pos[nextCow] = 0;
                cnt--;
                break;
            }
            if (cereal[arr[nextCow].se] < nextCow && cereal[arr[nextCow].se]) {
                pos[nextCow] = 0;
                cnt--;
                break;
            }
            pos[nextCow] = 2;
            swap(nextCow, cereal[arr[nextCow].se]);
        }
        ans[i] = cnt;
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}
