// Educational Codeforces Round 151 (Rated for Div. 2)
// B. Come Together
// https://codeforces.com/contest/1845/problem/B


#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int T;

void solve() {
    pair<int, int> A, B, C;
    cin >> A.f >> A.s >> B.f >> B.s >> C.f >> C.s;
    array<int, 4> rect1 = {min(A.f, B.f), min(A.s, B.s), max(A.f, B.f), max(A.s, B.s)}; // x1, y1, x2, y2
    array<int, 4> rect2 = {min(A.f, C.f), min(A.s, C.s), max(A.f, C.f), max(A.s, C.s)}; // x1, y1, x2, y2
    int xOverlap = min(rect1[2], rect2[2]) - max(rect1[0], rect2[0]);
    int yOverlap = min(rect1[3], rect2[3]) - max(rect1[1], rect2[1]);
    long long ans = xOverlap+yOverlap+1;
    cout << ans << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
