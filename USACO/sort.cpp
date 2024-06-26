#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> N;
    vector<int> arr(N+1);
    vector<int> sortedArr(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        sortedArr[i] = arr[i];
    }
    sort(sortedArr.begin()+1, sortedArr.end());
    map<int, int> A, B;
    int ans = 0;
    int cur = 0;
    for (int i = 1; i <= N-1; i++) {
        A[arr[i]]++;
        B[sortedArr[i]]++;
        cur++;
        if (B[arr[i]] > 0) {
            cur--;
            A[arr[i]]--;
            B[arr[i]]--;
        }
        if (A[sortedArr[i]] > 0) {
            cur--;
            A[sortedArr[i]]--;
            B[sortedArr[i]]--;
        }
        ans = max(ans, cur);
    }

    cout << max(ans, 1) << "\n";
}
