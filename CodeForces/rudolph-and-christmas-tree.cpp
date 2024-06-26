#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

int T, N;
long double B, H;

double findArea(double base, double height) {
    return 0.5*base*height;
}

void solve() {
    cin >> N >> B >> H;
    vector<double> arr(N);
    for (auto &v: arr) {
        cin >> v;
        v += H;
    }
    sort(arr.begin(), arr.end());
    double area = 0;
    for (int i = N-1; i >= 0; i--) {
        area += findArea(B, H);
        if (i < N-1 && arr[i+1] < arr[i]+H) { // No Overlap
            double h2 = (arr[i]+H)-arr[i+1];
            double b2 = B*h2/H;
            area -= findArea(b2, h2);
        }
    }
    cout << setprecision(15) << area << "\n";
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
