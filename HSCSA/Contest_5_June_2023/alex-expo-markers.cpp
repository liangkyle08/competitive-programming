#include <bits/stdc++.h>
using namespace std;

int N, M, K;

int main() {
    cin >> N >> M >> K;
    long long breaks = 0;
    for (int i = 1; i <= K; i++) {
        int len;
        cin >> len;
        int prev = -1;
        while (len--) {
            int cur;
            cin >> cur;
            if (cur != prev+1 && prev != -1) {
                breaks++;
            }
            prev = cur;
        }
    }
    cout << 2*breaks+K-M;
}
