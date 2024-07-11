#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const long long LL_INF = (1LL<<60);

const int MAX_N = 250000;

int N;
int A[MAX_N+5];
int B[MAX_N+5];
bool use[MAX_N+5];

struct cmp {
    bool operator()(int X, int Y) {
        return B[X] < B[Y];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }
    priority_queue<int, vector<int>, cmp> pq;
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += A[i];
        if (!pq.empty() && sum < B[i] && B[pq.top()] > B[i]) {
            use[pq.top()] = false;
            sum += B[pq.top()];
            pq.pop();
        }
        if (sum >= B[i]) {
            use[i] = true;
            sum -= B[i];
            pq.push(i);
        }
    }
    cout << (int)pq.size() << "\n";
    for (int i = 1; i <= N; i++) {
        if (!use[i]) continue;
        cout << i << " ";
    } cout << "\n";
}
