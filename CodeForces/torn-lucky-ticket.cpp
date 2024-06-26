#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
string arr[200001];
int len[200001];
int total[200001];
map<int, long long> freq[6];

void debug() {
    int cnt = 0;
    int C[200001];
    int D[200001];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            string t = arr[i]+arr[j];
            if ((int)t.size() % 2 == 1) continue;
            int A = 0;
            int B = 0;
            for (int k = 0; k < t.size()/2; k++) {
                A += t[k]-'0';
            }
            for (int k = t.size()/2; k < t.size(); k++) {
                B += t[k]-'0';
            }
            if (A != B) continue;
            cnt++;
            cout << cnt << ":\t" << i << "\t" << j << "\t" << arr[i] << "\t" << arr[j] << "\n";
            C[i]++;
            D[j]++;
        }
    }
    //cout << "\n\n~~~~~~~~~~~~~\n\n\n";
    for (int i = 1; i <= N; i++) {
        cout << i << ":\t" << C[i] << "\t" << D[i] << "\t" << C[i]+D[i] << "\n";
    }
    //cout << "\n\n~~~~~~~~~~~~~\n\n\n";
}

void solve() {
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        int cur = 0;
        int cnt = 0;
        for (int j = len[i]-1; j >= len[i]/2; j--) {
            if (j < len[i]-1) {
                cur += (arr[i][j+1]-'0');
            }
            //cout << 2*(j+1)-len[i] << " " << total[i] - 2*cur << "\n";
            ans += freq[2*(j+1)-len[i]][total[i]-2*cur];
            cnt += freq[2*(j+1)-len[i]][total[i]-2*cur];
        }
        //cout << ans << ":\t" << i << "\t" << cnt << "\n";
    }
    //cout << "\n\n~~~~~~~~~~~~~\n\n\n";
    //cout << '\n';
    for (int i = 1; i <= N; i++) {
        int cur = 0;
        int cnt = 0;
        for (int j = 1; j <= len[i]/2; j++) {
            if (j > 0) {
                cur += (arr[i][j-1]-'0');
            }
            //cout << len[i]-2*(j) << " " << total[i]-2*cur << "\n";
            ans += freq[len[i]-2*(j)][total[i]-2*cur];
            cnt += freq[len[i]-2*(j)][total[i]-2*cur];
        }
        //cout << ans << ":\t" << i << "\t" << cnt << "\n";
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        len[i] = (int)arr[i].size();
        total[i] = 0;
        for (int j = 0; j < len[i]; j++) {
            total[i] += (arr[i][j]-'0');
        }
        freq[len[i]][total[i]]++;
        //cout << "U: " << len[i] << " " << total[i] << "\n";
    }
    //debug();
    solve();
}
