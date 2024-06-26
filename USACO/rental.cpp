#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M, R;
long long cows[1000001]; // gallons
pair<long long, long long> milk[1000001]; // cents per gallon
long long rent[1000001]; // cents
long long A[1000005]; // Milk
long long B[1000005]; // Rent

void initializeA() {
    int j = 1;
    for (int i = 1; i <= N; i++) {
        long long curAmt = cows[i];
        A[i] = A[i-1];
        while (j <= M && curAmt > 0) {
            if (curAmt >= milk[j].se) {
                A[i] += milk[j].fi*milk[j].se;
                curAmt -= milk[j].se;
                j++;
                continue;
            }
            A[i] += milk[j].fi*curAmt;
            milk[j].se -= curAmt;
            break;
        }
    }
}

void initializeB() {
    int j = 1;
    for (int i = N; i >= 1; i--) {
        B[i] = B[i+1];
        if (j <= R) {
            B[i] += rent[j];
            j++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++) {
        cin >> cows[i];
    }
    sort(cows+1, cows+N+1);
    reverse(cows+1, cows+N+1);
    for (int i = 1; i <= M; i++) {
        cin >> milk[i].se >> milk[i].fi;
    }
    sort(milk+1, milk+M+1);
    reverse(milk+1, milk+M+1);
    for (int i = 1; i <= R; i++) {
        cin >> rent[i];
    }
    sort(rent+1, rent+R+1);
    reverse(rent+1, rent+R+1);
    initializeA();
    initializeB();
    long long ans = max(B[1], A[N]);
    for (int i = 1; i < N; i++) {
        ans = max(ans, A[i]+B[i+1]);
    }
    cout << ans << "\n";
}
