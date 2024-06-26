#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N, P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> N >> P;
        string f, s;
        cin >> f >> s;
        vector<pair<int, int>> A, B, C;
        int len = 0;
        for (int i = 1; i <= N; i++) {
            len++;
            if (i == N || f[i-1] != f[i]) {
                A.push_back({(f[i-1]-'1')+1, len});
                len = 0;
            }
        }
        len = 0;
        for (int i = 1; i <= N; i++) {
            len++;
            if (i == N || s[i-1] != s[i]) {
                B.push_back({(s[i-1]-'1')+1, len});
                len = 0;
            }
        }
        vector<pair<pair<int, int>, int>> moves;
        if (A.back().fi == B.back().fi) {
            if ((int)A.size() > 1) {
                B.back().se += A.back().se;
                moves.push_back({{1, 2}, A.back().se});
                A.pop_back();
            }
            else {
                A.back().se += B.back().se;
                moves.push_back({{2, 1}, B.back().se});
                B.pop_back();
            }
        }
        if ((int)A.size() > 1 || (int)B.size() > 1) {
            if ((int)A.size() > 1) {
                C.push_back(A.back());
                moves.push_back({{1, 3}, A.back().se});
                A.pop_back();
            }
            else {
                C.push_back(B.back());
                moves.push_back({{2, 3}, B.back().se});
                B.pop_back();
            }
            if (A.front().fi != C.front().fi) {
                while ((int)A.size() > 1) {
                    if (A.back().fi == B.back().fi) {
                        B.back().se += A.back().se;
                        moves.push_back({{1, 2}, A.back().se});
                        A.pop_back();
                    }
                    else {
                        C.back().se += A.back().se;
                        moves.push_back({{1, 3}, A.back().se});
                        A.pop_back();
                    }
                }
                while ((int)B.size() > 1) {
                    if (B.back().fi == A.back().fi) {
                        A.back().se += B.back().se;
                        moves.push_back({{2, 1}, B.back().se});
                        B.pop_back();
                    }
                    else {
                        C.back().se += B.back().se;
                        moves.push_back({{2, 3}, B.back().se});
                        B.pop_back();
                    }
                }
            }
            else {
                while ((int)B.size() > 1) {
                    if (B.back().fi == A.back().fi) {
                        B.back().se += A.back().se;
                        moves.push_back({{1, 2}, A.back().se});
                        A.pop_back();
                    }
                    else {
                        C.back().se += B.back().se;
                        moves.push_back({{2, 3}, B.back().se});
                        B.pop_back();
                    }
                }
                while ((int)A.size() > 1) {
                    if (A.back().fi == B.back().fi) {
                        A.back().se += B.back().se;
                        moves.push_back({{2, 1}, B.back().se});
                        B.pop_back();
                    }
                    else {
                        C.back().se += A.back().se;
                        moves.push_back({{1, 3}, A.back().se});
                        A.pop_back();
                    }
                }
            }
            if (C.front().fi == A.front().fi) {
                A.back().se += C.back().se;
                moves.push_back({{3, 1}, C.back().se});
                C.pop_back();
            }
            else {
                B.back().se += C.back().se;
                moves.push_back({{3, 2}, C.back().se});
                C.pop_back();
            }
        }
        cout << (int)moves.size() << "\n";
        if (P > 1) {
            for (auto [pi, cnt]: moves) {
                cout << pi.fi << " " << pi.se << "\n";
            }
        }
    }
}
