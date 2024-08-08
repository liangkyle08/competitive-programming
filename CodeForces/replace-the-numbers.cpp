#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

int Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Q;
    vector<int> A;
    vector<pair<int, pair<int, int>>> buffer;
    while (Q--) {
        int T, X, Y;
        cin >> T;
        if (T == 1) {
            cin >> X;
            A.push_back(X);
        }
        else {
            cin >> X >> Y;
            buffer.push_back({(int)A.size() - 1, {X, Y}});
        }
    }
    map<int, int> val;
    vector<int> B;
    for (int i = (int)A.size() - 1; i >= 0; i--) {
        while (!buffer.empty() && buffer.back().fi == i) {
            if (val[buffer.back().se.se]) {
                val[buffer.back().se.fi] = val[buffer.back().se.se];
            }
            else {
                val[buffer.back().se.fi] = buffer.back().se.se;
            }
            buffer.pop_back();
        }
        B.push_back((val[A[i]] ? val[A[i]] : A[i]));
    }
    for (int i = (int)B.size() - 1; i >= 0; i--) {
        cout << B[i] << " ";
    } cout << "\n";
}
