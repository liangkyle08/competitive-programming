#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

const int MAX_N = 1000;

int N;
char t[2*MAX_N+1][2*MAX_N+1];
int arr[2*MAX_N+1][2*MAX_N+1];
int arr2[2*MAX_N+1][2*MAX_N+1];
int pos[2*MAX_N+1][2*MAX_N+1];
int neg[2*MAX_N+1][2*MAX_N+1];
bool state = false; // false = A, true = B

int solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            bool flag = (arr[i][j] == 2 || arr[i][j] == -1);
            neg[i][j] = neg[i-1][j]+neg[i][j-1]-neg[i-1][j-1]+flag;
            flag = (arr[i][j] == 1);
            pos[i][j] = pos[i-1][j]+pos[i][j-1]-pos[i-1][j-1]+flag;
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 0) continue;
            int low = 0;
            int high = min(N-i, N-j);
            if (state) high /= 2;
            while (low < high) {
                int mid = (low+high+1)/2;
                if (state) mid *= 2;
                if (neg[i+mid][j+mid]-neg[i-1][j+mid]-neg[i+mid][j-1]+neg[i-1][j-1] >= 1) {
                    if (state) {
                        high = mid/2-1;
                    }
                    else {
                        high = mid-1;
                    }
                }
                else {
                    if (state) {
                        low = mid/2;
                    }
                    else {
                        low = mid;
                    }
                    int val = pos[i+mid][j+mid]-pos[i-1][j+mid]-pos[i+mid][j-1]+pos[i-1][j-1];
                    if (val > ans) {
                        ans = val;
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N;
    bool seenA = false;
    bool seenB = false;
    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++) {
            if (s[j-1] == 'A') {
                arr[i][j] = 1;
                seenA = true;
            }
            if (s[j-1] == 'B') {
                arr[i][j] = 2;
                seenB = true;
            }
            if (s[j-1] == '.') arr[i][j] = -1;
            t[i][j] = s[j-1];
        }
    }
    // Alice, no rotation
    int A = max(solve(), (int)seenA);
    // Bob, rotate 45 degrees
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 1) arr[i][j] = 2;
            else if (arr[i][j] == 2) arr[i][j] = 1;
            arr2[i+j-1][N-i+j] = arr[i][j];
            neg[i][j] = 0;
            pos[i][j] = 0;
        }
    }
    N = 2*N-1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] = arr2[i][j];
        }
    }
    if (N > 1) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][j] != 0 || arr[i][j+1] != 0) break;
                arr[i][j] = -1;
                if (arr[i][j+2] != 0) break;
            }
            for (int j = N; j >= 1; j--) {
                if (arr[i][j] != 0 || arr[i][j-1] != 0) break;
                arr[i][j] = -1;
                if (arr[i][j-2] != 0) break;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
        }
    }
    state = true;
    int B = max(solve(), (int)seenB);
    cout << A << " " << B << "\n";
}
