#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    vector<long long> arr(N);
    int minPos = 0;
    long long curMin = (1<<30);
    long long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        total += arr[i];
        if (arr[i] <= curMin) {
            minPos = i;
            curMin = arr[i];
        }
    }
    rotate(arr.begin(), arr.begin()+((minPos + 1) % N), arr.end());
    vector<long long> diff(N+1);
    vector<int> s;
    for (int i = N-1; i >= 0; i--) {
        while (!s.empty() && arr[s.back()] >= arr[i]) {
            if ((int)s.size() > 1) {
                int t1 = s.back();
                int t2 = s[(int)s.size()-2];
                int delta = arr[t1]-arr[t2];
                diff[t2-t1] += delta;
                diff[t2-i] -= delta;
            }
            s.pop_back();
        }
        s.push_back(i);
    }
    while ((int)s.size() > 1) {
        int t1 = s.back();
        int t2 = s[(int)s.size()-2];
        int delta = arr[t1]-arr[t2];
        diff[t2-t1] += delta;
        diff[t2+1] -= delta;
        s.pop_back();
    }
    for (int i = 1; i <= N; i++) {
        diff[i] += diff[i-1];
        total -= diff[i];
        cout << total << "\n";
    }
}
