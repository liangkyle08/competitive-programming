#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
int monthLen[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        vector<int> days(N+1);
        for (int i = 1; i <= N; i++) {
            cin >> days[i];
        }
        vector<int> months;
        for (int i = 1; i <= N; i++) {
            if ((i < N && days[i+1] == 1)) { // End of a month
                months.push_back(days[i]);
            }
        }
        int feb = -1;
        for (int i = 0; i < (int)months.size(); i++) { // Find Feb
            if (months[i] == 28 || months[i] == 29) {
                feb = i;
                break;
            }
        }
        if (feb >= 0) {
            while (feb-12 >= 0) {
                if (feb)
                feb -= 12;
            }
            continue;
        }
    }
}
