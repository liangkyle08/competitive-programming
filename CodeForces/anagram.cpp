#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
char s[100001];
char t[100001];
string str_s, str_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> str_s >> str_t;
    N = (int)str_s.size();
    for (int i = 0; i < N; i++) {
        s[i] = str_s[i];
        t[i] = str_t[i];
    }
    map<char, int> freq;
    for (int i = 0; i < N; i++) {
        freq[s[i]]++;
        freq[t[i]]--;
    }
    int minMoves = 0;
    map<char, int> addChar;
    map<char, int> removeChar;
    char lastChar = 'A';
    for (char c = 'A'; c <= 'Z'; c++) {
        if (freq[c] > 0) {
            minMoves += freq[c];
            removeChar[c] = freq[c];
        }
        if (freq[c] < 0) {
            addChar[c] = -freq[c];
            lastChar = max(lastChar, c);
        }
    }
    int L = 0;
    for (char u = 'A'; u <= 'Z'; u++) {
        while (addChar[u] > 0) {
            while ((removeChar[s[L]] == 0 || (u > s[L])) && L < N) {
                L++;
            }
            if (L >= N) break;
            removeChar[s[L]]--;
            addChar[u]--;
            s[L] = u;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << s[i];
    } cout << "\n";
    int R = N-1;
    for (char u = 'Z'; u >= 'A'; u--) {
        while (addChar[u] > 0) {
            while ((removeChar[s[R]] == 0 || (u < s[R])) && R >= 0) {
                R--;
            }
            if (R < 0) break;
            removeChar[s[R]]--;
            addChar[u]--;
            s[R] = u;
        }
    }
    cout << minMoves << "\n";
    for (int i = 0; i < N; i++) {
        cout << s[i];
    } cout << "\n";
}
