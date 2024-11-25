#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 2e5;

int N;
int A[MAX_N + 5];
bool mx[MAX_N + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int cur = 0;
    for (int i = 1; i < N; i++) {
        if (A[i] < cur) continue;
        mx[i] = true;
        cur = A[i];
    }
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (mx[i]) continue;
        ans.push_back(i);
    }
    for (int i = N; i >= 1; i--) {
        if (!mx[i]) continue;
        ans.push_back(i);
    }
    long long total = 0;
    int prev = N ;
    for (int i = N - 1; i >= 1; i--) {
        if (!mx[i]) continue;
        total += (long long)A[i] * (long long)(prev - i);
        prev = i;
    }
    cout << total << "\n";
    for (auto &v: ans) {
        cout << v << " ";
    } cout << "\n";
}
