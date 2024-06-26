#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int A[20];
vector<pair<int, int>> opers;

void oper(int L, int R) {
    vector<int> cnt(N+2);
    for (int i = L; i <= R; i++) {
        if (A[i] <= N) {
            cnt[A[i]]++;
        }
    }
    int mex = 0;
    while (cnt[mex]) mex++;
    for (int i = L; i <= R; i++) A[i] = mex;
    opers.push_back({L, R});
}

void build(int L, int R) {
    if (L == R) {
        if (A[L]) oper(L, R);
        return;
    }
    build(L, R-1);
    if (A[R] != R-L) {
        oper(L, R);
        build(L, R-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int ans = 0;
    int finalLen = 0;
    for (int len = 0; len < (1<<N); len++) {
        int temp = 0;
        for (int L = 1; L <= N; L++) {
            if (len & (1<<(L-1))) {
                int R = L;
                while (R <= N && (len & (1<<R))) R++;
                temp += (R-L+1)*(R-L+1);
                L = R;
            }
            else {
                temp += A[L];
            }
        }
        if (temp > ans){
            ans = temp;
            finalLen = len;
        }
    }
    for (int L = 1; L <= N; L++) {
        if (!(finalLen & (1<<(L-1)))) continue;
        int R = L;
        while (R <= N && (finalLen & (1<<R))) R++;
        build(L, R);
        oper(L, R);
        L = R;
    }
    cout << ans << " " << (int)opers.size() << "\n";
    for (auto [u, v]: opers) {
        cout << u << " " << v << "\n";
    }
}
