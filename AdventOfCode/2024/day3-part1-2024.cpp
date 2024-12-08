#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

int N;
string s;
vector<char> stk1;
vector<int> stk2, stk3;

void clearAll() {
    stk1.clear();
    stk2.clear();
    stk3.clear();
}

int toInt(char x) {
    return x - '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s;
    N = (int)s.size();
    for (int i = 0; i < N; i++) { // mul(###,###)
        if (s[i] == 'm') {
            clearAll();
            stk1.push_back(s[i]);
            continue;
        }
        if (s[i] == 'u') {
            if (!stk1.empty() && stk1.back() == 'm') {
                stk1.push_back(s[i]);
            }
            else {
                clearAll();
            }
            continue;
        }
        if (s[i] == 'l') {
            if (!stk1.empty() && stk1.back() == 'u') {
                stk1.push_back(s[i]);
            }
            else {
                clearAll();
            }
            continue;
        }
        if (s[i] == '(') {
            if (!stk1.empty() && stk1.back() == 'l') {
                stk1.push_back(s[i]);
            }
            else {
                clearAll();
            }
            continue;
        }
        if (s[i] == ',') {
            if (!stk1.empty() && stk1.back() == '(') {
                stk1.push_back(s[i]);
            }
            else {
                clearAll();
            }
            continue;
        }
        if (0 <= toInt(s[i]) && toInt(s[i]) <= 9) {
            if (!stk1.empty() && stk1.back() == '(') {
                stk2.push_back(toInt(s[i]));
            }
            else if (!stk1.empty() && stk1.back() == ',') {
                stk3.push_back(toInt(s[i]));
            }
            else {
                clearAll();
            }
            continue;
        }
        if (s[i] == ')') {
            if (!stk1.empty() && stk1.back() == ',') {
                stk1.push_back(s[i]);
                if (1 <= (int)stk2.size()
                    && (int)stk2.size() <= 3
                    && 1 <= (int)stk3.size()
                    && (int)stk3.size() <= 3) {
                    int v1 = 0;
                    int v2 = 0;
                    int M = (int)stk2.size();
                    for (int j = 0; j < M; j++) {

                    }
                }
            }
            clearAll();
            continue;
        }
    }
}
