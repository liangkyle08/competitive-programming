#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int MAX_POW2 = 12;
const int MAX_POW3 = 8;

int N;
pair<int, int> arr[1001];
int pow2[MAX_POW2+1];
int pow3[MAX_POW3+1];
int sumPow2[10000];
int sumPow3[10000];
int ans[1001];

int sumBase2(int X) {
    int curPow = MAX_POW2;
    int sum = 0;
    while (curPow--) {
        sum += X/pow2[curPow];
        X %= pow2[curPow];
    }
    return sum;
}

int sumBase3(int X) {
    int curPow = MAX_POW3;
    int sum = 0;
    while (curPow--) {
        sum += X/pow3[curPow];
        X %= pow3[curPow];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    pow2[0] = 1;
    pow3[0] = 1;
    for (int i = 1; i <= MAX_POW2; i++) {
        pow2[i] = pow2[i-1]*2;

    }
    for (int i = 1; i <= MAX_POW3; i++) {
        pow3[i] = pow3[i-1]*3;
    }
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    sort(arr+1, arr+N+1);
    int cur = 0;
    int j = 1;
    for (int i = 1; i <= arr[N].fi; i++) {
        if (i <= pow2[MAX_POW2]) {
            sumPow2[i] = sumBase2(i);
        }
        if (i <= pow3[MAX_POW3]) {
            sumPow3[i] = sumBase3(i);
        }
        if (sumPow2[i / pow2[MAX_POW2]]+sumPow2[i % pow2[MAX_POW2]]
            == sumPow3[i / pow3[MAX_POW3]]+sumPow3[i % pow3[MAX_POW3]]) {
            cur++;
        }
        while (j <= N && arr[j].fi == i) {
            ans[arr[j].se] = cur;
            j++;
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
}
