#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 250000;

int N;
int A[MAX_N+5];
int B[MAX_N+5];

vector<int> localAns, globalAns;

int check(int X) {
    long long sum = 0;
    int total = 0;
    for (int i = 1; i <= N; i++) {
        sum += A[i];
        if (sum - B[i] < X) continue;
        localAns.push_back(i);
        sum -= B[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    long long low = 0;
    long long high = 1e9;
    while (low < high) {
        long long mid = (low + high + 1) / 2;
        if (check(mid)) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low << "\n";
    for (auto v: ans) {
        cout << v << " ";
    } cout << "\n";

}
