#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    long long N = (int)s.size();
    string order = "bessie";
    vector<int> tokens(7);
    long long total = 0;
    for (int i = 0; i < N; i++) {
        tokens[0]++;
        for (int j = 5; j >= 0; j--) {
            if (s[i] == order[j]) {
                tokens[j+1] += tokens[j];
                tokens[j] = 0;
            }
        }
        total += tokens[6]*(N-i);
        tokens[0] += tokens[6];
        tokens[6] = 0;
    }
    cout << total << "\n";
}
