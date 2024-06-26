#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, K;
int arr[65537];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    map<int, int> len;
    set<int> endPoints;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+N+1);
    for (int i = 1; i <= N; i++) {
        int val = (arr[i]+11)/12;
        if (endPoints.find(val) == endPoints.end()) {
            endPoints.insert(val);
            len[val] = 1;
        }
        if (endPoints.find(val-1) != endPoints.end()) {
            endPoints.erase(val-1);
            len[val] += len[val-1];
            len[val-1] = 0;
        }
    }
    int total = 0;
    for (auto v: endPoints) {
        total += 12*len[v];
    }
    if ((int)endPoints.size() <= K-1) {
        cout << total << "\n";
        exit(0);
    }
    endPoints.insert(0);
    multiset<int> seg;
    for (auto v: endPoints) {
        if (v == 0) continue;
        int u = *(--endPoints.find(v));
        seg.insert((v-len[v])-u);
    }
    for (int i = 1; i <= (int)endPoints.size()-K; i++) {
        total += 12*(*seg.begin());
        seg.erase(seg.begin());
    }
    cout << total << "\n";
}
