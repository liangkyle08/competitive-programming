#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
long long B;
long long A[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> B;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int L = 1;
    int R = 1;
    long long total = 0;
    while (L <= N && R <= N) {
        while (total+A[R] <= B && R <= N) {

        }
    }
}
