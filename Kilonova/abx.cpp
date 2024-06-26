#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const long long INF = (1LL<<60);

int N;
long long M;
long long arr[5001];
long long ans[5001];
vector<long long> s;

long long binSearchUpper(long long X) {
    long long high = min((long long)1e9, (long long)sqrtl(M));
    long long low = 1;
    while (low < high) {
        long long mid = (high+low)/2;
        if (powl(mid, 2) >= X) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    return powl(low, 2);
}

long long binSearchLower(long long X) {
    long long high = min((long long)1e9, (long long)sqrtl(M));
    long long low = 1;
    while (low < high) {
        long long mid = (high+low)/2;
        if (powl(mid, 2) > X) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    return powl(low-1, 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("abx.in", "r", stdin);
    freopen("abx.out", "w", stdout);
    cin >> N >> M;
    // Powers that aren't squares
    s.push_back(1);
    for (int a = 2; a <= 2000000; a++) {
        for (int b = 3; b <= (long long)(18/log10(a)); b++) {
            if ((long long)powl(a, b) > M) continue;
            s.push_back((long long)powl(a, b));
        }
    }
    s.push_back(-INF);
    s.push_back(INF);
    sort(s.begin(), s.end());
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        set<pair<long long, long long>> quickCheck;
        // Search for squares separately
        long long R1 = binSearchUpper(arr[i]);
        long long L1 = binSearchLower(arr[i]);
        long long R2 = *lower_bound(s.begin(), s.end(), arr[i]);
        long long L2 = *(--upper_bound(s.begin(), s.end(), arr[i]));
        if (1 <= R1 && R1 <= M) quickCheck.insert({abs(arr[i]-R1), R1});
        if (1 <= L1 && L1 <= M) quickCheck.insert({abs(arr[i]-L1), L1});
        if (1 <= R2 && R2 <= M) quickCheck.insert({abs(arr[i]-R2), R2});
        if (1 <= L2 && L2 <= M) quickCheck.insert({abs(arr[i]-L2), L2});
        quickCheck.insert({INF, 1});
        cout << (*quickCheck.begin()).se << "\n";
    }
}
