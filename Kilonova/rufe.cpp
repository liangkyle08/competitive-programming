#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1e9;

struct Rect {
    long long cornerVal;
    int height;
    int width;
};

int N, M, A, B;
long long K;
Rect rects[4];

long long tri(long long n) {
    return n * (n + 1) / 2;
}

bool check(long long val) {
    long long total = 0;
    for (int i = 0; i < 4; i++) {
        long long cornerVal = rects[i].cornerVal;
        long long height = rects[i].height;
        long long width = rects[i].width;
        if (cornerVal < val) continue;
        long long dist = cornerVal - val + 1;
        long long cur = tri(dist);
        if (dist > height) cur -= tri(dist - height);
        if (dist > width) cur -= tri(dist - width);
        total += cur;
    }
    return total >= K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("rufe.in", "r", stdin);
    freopen("rufe.out", "w", stdout);
    cin >> N >> M >> A >> B >> K;
    rects[0] = {A + B - 2, A - 1, B - 1};
    rects[1] = {A + (M - B) - 1, A - 1, (M - B) + 1};
    rects[2] = {(N - A) + B - 1, (N - A) + 1, B - 1};
    rects[3] = {(N - A) + (M - B), (N - A) + 1, (M - B) + 1};
    long long high = 2e9;
    long long low = 0;
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (check(mid)) {
            low = mid;
        }
        else {
            high = mid - 1;
        }
    }
    cout << low << "\n";
}
