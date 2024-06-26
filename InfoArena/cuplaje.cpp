#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N, M;
pair<int, int> A[200001];
pair<int, int> B[200001];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> A[i].fi;
        A[i].se = i;
    }
    for (int i = 1; i <= M; i++) {
        cin >> B[i].fi;
        B[i].se = i;
    }
}
