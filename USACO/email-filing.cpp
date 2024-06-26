#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, M, N, K;
int email[100001];

struct Cmd {
    bool operator()(const int& A, const int& B) const {
        return email[A] <= email[B];
    }
};

void solve() {
    cin >> M >> N >> K;
    vector<int> freq(M+1);
    for (int i = 1; i <= N; i++) {
        cin >> email[i];
        freq[email[i]]++;
    }
    int curFolder = 1;
    vector<bool> seen(N+1);
    set<int, Cmd> curEmails;
    for (int i = 1; i < K; i++) {
        curEmails.insert(i);
    }
    for (int i = K; i <= N; i++) {
        curEmails.insert(i);
        while (!curEmails.empty()
               && curFolder <= email[*curEmails.begin()]
               && email[*curEmails.begin()] <= curFolder+K-1) {
            seen[*curEmails.begin()] = true;
            freq[email[*curEmails.begin()]]--;
            curEmails.erase(curEmails.begin());
        }
        while (freq[curFolder] == 0) curFolder++;
        while ((int)curEmails.size() > K) {
            curEmails.erase(--curEmails.end());
        }
    }
    curEmails.clear();
    bool flag = true;
    for (int i = N; i >= 1; i--) {
        if (seen[i]) continue;
        if ((int)curEmails.size() >= K) {
            flag = false;
            break;
        }
        curEmails.insert(i);
        while (!curEmails.empty()
               && curFolder <= email[*curEmails.begin()]
               && email[*curEmails.begin()] <= curFolder+K-1) {
            seen[*curEmails.begin()] = true;
            freq[email[*curEmails.begin()]]--;
            curEmails.erase(curEmails.begin());
        }
        while (freq[curFolder] == 0) curFolder++;
    }
    if (flag && curEmails.empty()) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        solve();
    }
}
