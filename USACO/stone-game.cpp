#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;
int arr[100001];
long long dist[1000002];
long long cnt[1000001]; // number of items in arr >= to i;
map<int, long long> freq;

int main() {
    cin >> N;
    int MAX_A = 0;
    int MIN_A = 1e6+1;
    set<int> s;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
        s.insert(arr[i]);
        MAX_A = max(MAX_A, arr[i]);
        MIN_A = min(MIN_A, arr[i]);
    }
    auto it = --freq.end();
    for (int i = MAX_A; i >= (MIN_A/2)+1; i--) {
        cnt[i] = cnt[i+1];
        while (i <= it->fi) {
            cnt[i] += it->se;
            if (it == freq.begin()) break;
            --it;
        }
        cnt[i] = min(cnt[i], (long long)N);
    }
    long long ans = 0LL;
    for (int i = MAX_A; i >= (MIN_A/2)+1; i--) {
        int key = MAX_A;
        if (i != MAX_A) key = *s.upper_bound(i);
        for (auto j = 2*i; j <= MAX_A; j += i) {
            if (s.lower_bound(j) == s.end()) break;
            key = *s.lower_bound(j);
        }
        dist[i] = freq[key];
        if (i != key) dist[i] += freq[i];
        if (dist[i] % 2 == 1) {
            ans += cnt[i];
        }
    }
    cout << ans << "\n";
}
