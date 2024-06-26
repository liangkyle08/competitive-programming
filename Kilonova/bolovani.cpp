#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

struct Rock {
    long long t, d, s;
    int ind;
};

int N;
Rock arr[10001]; // time/duration, deadline, ind
bool chosen[10001];

bool cmp(Rock A, Rock B) {
    return A.d < B.d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("bolovani.in", "r", stdin);
    freopen("bolovani.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].t >> arr[i].d;
        arr[i].ind = i;
    }
    sort(arr+1, arr+N+1, cmp);
    long long curTime = 0;
    int earlyBoulder = 0;
    for (int i = 1; i <= N; i++) {
        if (curTime+arr[i].t <= arr[i].d) {
            chosen[i] = true;
            earlyBoulder++;
            arr[i].s = curTime+1;
            curTime += arr[i].t;
        }
        else {
            int k = -1;
            for (int j = 1; j <= N; j++) {
                if (!chosen[j]) continue;
                if (k == -1 || arr[k].t < arr[j].t) {
                    k = j;
                }
            }
            if (k != -1 && arr[k].t > arr[i].t) {
                chosen[k] = false;
                curTime -= arr[k].t;
                arr[i].s = curTime+1;
                for (int j = k+1; j <= N; j++) {
                    if (!chosen[j]) continue;
                    arr[j].s -= arr[k].t;
                }
                chosen[i] = true;
                curTime += arr[i].t;
            }
        }
    }
    vector<pair<long long, long long>> ans(N+1);
    for (int i = 1; i <= N; i++) {
        if (chosen[i]) {
            ans[arr[i].ind] = {arr[i].s, arr[i].s+arr[i].t-1};
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!chosen[i]) {
            ans[arr[i].ind] = {curTime+1, curTime+arr[i].t};
            curTime += arr[i].t;
        }
    }
    cout << earlyBoulder << "\n";
    for (int i = 1; i <= N; i++) {
        cout << ans[i].fi << " " << ans[i].se << "\n";
    }
}
