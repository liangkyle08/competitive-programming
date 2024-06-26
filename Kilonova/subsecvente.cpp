#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
string arr[5];

bool check(int x) {
    map<string, array<bool, 5>> freq;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j+x <= (int)arr[i].size(); j++) {
            freq[arr[i].substr(j, x)][i] = true;
        }
    }
    bool pos = false;
    for (auto [u, v]: freq) {
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            cnt += v[i];
        }
        if (cnt == N) {
            pos = true;
            break;
        }
    }
    return pos;
}

int main() {
    freopen("subsecvente.in", "r", stdin);
    freopen("subsecvente.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    int high = 60;
    int low = 0;
    while (low < high) {
        int mid = (low+high+1)/2;
        if (check(mid)) {
            low = mid;
        }
        else {
            high = mid-1;
        }
    }
    cout << low << "\n";
}