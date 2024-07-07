#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);

int T, N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N >> K;
        vector<int> arr;
        int i = 0;
        while ((1 << (i + 1)) <= K) i++;
        arr.push_back(K - (1 << i));
        arr.push_back(K + 1);
        arr.push_back(K + (1 << i) + 1);
        for (int j = 0; j < 20; j++) {
            if (j != i) {
                arr.push_back((1 << j));
            }
        }
        cout << (int)arr.size() << "\n";
        for (auto v: arr) {
            cout << v << " ";
        } cout << "\n";
    }
}
