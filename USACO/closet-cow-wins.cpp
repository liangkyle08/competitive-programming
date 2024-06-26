#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int K, M, N;
vector<long long> P;
long long T[200001];
long long arr[200001];
long long pSum[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K >> M >> N;
    P.resize(K+1);
    vector<pair<long long, long long>> temp(K+1);
    for (int i = 1; i <= K; i++) {
        cin >> temp[i].fi >> temp[i].se;
    }
    sort(temp.begin()+1, temp.end());
    for (int i = 1; i <= K; i++) {
        P[i] = temp[i].fi;
        T[i] = temp[i].se;
    }
    for (int i = 1; i <= K; i++) {
        pSum[i] = pSum[i-1]+T[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> arr[i];
    }
    sort(arr+1, arr+M+1);
    vector<long long> cnt;
    for (int i = 1; i <= M; i++) {
        long long dist = (1LL<<30);
        if (i > 1) dist = (arr[i]-arr[i-1])/2;
        int L1 = lower_bound(P.begin()+1, P.end(), arr[i]-dist)-P.begin();
        int R1 = upper_bound(P.begin()+1, P.end(), arr[i])-P.begin()-1;
        dist = (1LL<<30);
        if (i < M) dist = (arr[i+1]-arr[i])/2;
        int L2 = lower_bound(P.begin()+1, P.end(), arr[i])-P.begin();
        int R2 = upper_bound(P.begin()+1, P.end(), arr[i]+dist)-P.begin()-1;
        if (L1 >= 1 && R1 <= K) {
            cnt.push_back(pSum[R1]-pSum[L1-1]);
            //cout << i << " " << L1 << " " << R1 << " " << pSum[R1]-pSum[L1-1] << "\n";
        }
        if (L2 >= 1 && R2 <= K) {
            cnt.push_back(pSum[R2]-pSum[L2-1]);
            //cout << i << " " << L2 << " " << R2 << " " << pSum[R2]-pSum[L2-1] << "\n";
        }
    }
    sort(cnt.begin(), cnt.end());
    long long total = 0LL;
    while (N-- && !cnt.empty()) {
        total += cnt.back();
        cnt.pop_back();
    }
    cout << total << "\n";
}
