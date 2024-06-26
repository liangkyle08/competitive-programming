#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int C, N;
string s;
char arr[10001];
bool parity[10001]; // Odd = 1, Even = 0;

bool cmp(vector<int> A, vector<int> B) {
    if ((int)A.size() != (int)B.size()) return (int)A.size() > (int)B.size();
    while (!A.empty() && A.back() == B.back()) {
        A.pop_back();
        B.pop_back();
    }
    if (A.empty()) return false;
    return A.back() > B.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("evip.in", "r", stdin);
    freopen("evip.out", "w", stdout);
    cin >> C >> s;
    N = (int)s.size();
    for (int i = 1; i <= N; i++) {
        arr[i] = s[i-1]-'0';
        parity[i] = arr[i] % 2;
    }
    bool curParity = 0;
    vector<int> mx;
    vector<int> cur;
    bool flag = false;
    long long total = 0;
    for (int i = 1; i <= N; i++) {
        if (parity[i] == 0 && curParity == 0) {
            cur.push_back(arr[i]);
            continue;
        }
        if (parity[i] == 0 && curParity == 1) {
            curParity = 0;
            flag = true;
            cur.push_back(arr[i]);
            continue;
        }
        if (parity[i] == 1 && curParity == 0) {
            if (flag) {
                if (cmp(cur, mx)) {
                    mx = cur;
                }
                for (int j = 0; j < (int)cur.size(); j++) {
                    if (cur[j] % 2 == 0) {
                        total += j*((int)cur.size()-j);
                        break;
                    }
                }
            }
            flag = false;
            curParity = 1;
            cur.clear();
        }
        if (parity[i] == 1 && curParity == 1) {
            cur.push_back(arr[i]);
        }
    }
    if (flag) {
        if (cmp(cur, mx)) {
            mx = cur;
        }
        for (int j = 0; j < (int)cur.size(); j++) {
            if (cur[j] % 2 == 0) {
                total += j*((int)cur.size()-j);
                break;
            }
        }
    }
    if (C == 1) {
        //cout << total << "\n";
    }
    else if (C == 2) {
        long long ans = (1LL<<60);
        for (int i = 2; i <= total; i++) {
            for (int j = i; j <= total; j += i) {
                if (total % j == 0) {
                    ans = min(ans, j+(total/j));
                }
            }
        }
        if (total <= 1) ans = total;
        cout << ans << "\n";
    }
    else {
        /*set<int> distinctVals;
        for (auto v: mx) {
            distinctVals.insert(v);
        }
        long long sum = 0;
        for (auto v: distinctVals) sum += v;
        long long ans = 0;
        long long len = (int)distinctVals.size();
        long long fact = 1;
        while (len > 0) {
            if (len > 1) fact *= (len-1);
            ans += (long long)powl(10, len-1);
            len--;
        }
        ans *= fact*sum;
        cout << ans << "\n";*/
    }
}
