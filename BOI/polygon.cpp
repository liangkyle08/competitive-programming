#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;
const int INF = (1<<30);
const int ALP = 26;
const long long LL_INF = (1LL<<60);

const int MAX_N = 1000;
const double PREC = 0.001;
static const double TWO_PI = 2.0 * acos(-1.0);

int N;
int length[MAX_N + 5];
double angle[MAX_N + 5];

double getAngle(double radius, double dist) {
    return 2.0 * asin(dist / (2.0 * radius));
}

int place(double radius, bool flag) {
    double anglePrec = asin(PREC / radius);
    angle[1] = 0.0;
    for (int i = 1; i <= N; i++) {
        angle[i + 1] = angle[i] + getAngle(radius, length[i]);
        if (i == 1 && flag) {
            angle[i + 1] = TWO_PI - angle[i + 1];
        }
    }
    if (angle[N + 1] > TWO_PI + anglePrec) return (flag ? +1 : -1);
    if (angle[N + 1] < TWO_PI - anglePrec) return (flag ? -1 : +1);
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> length[i];
    }
    sort(length + 1, length + N + 1, greater<int>());
    int maxLength = 0;
    for (int i = 2; i <= N; i++) {
        maxLength += length[i];
    }
    if (length[1] >= maxLength) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    double r2 = length[1];
    double r1 = r2 / 2.0;
    bool flag = (place(r1, false) > 0);
    while (place(r2, flag) < 0) {
        r1 = r2;
        r2 *= 2.0;
    }
    double r;
    while (true) {
        r = (r1 + r2) / 2.0;
        int mid = place(r, flag);
        if (mid == 0) break;
        if (mid < 0) r1 = r;
        if (mid > 0) r2 = r;
    }
    for (int i = 1; i <= N; i++) {
        cout << fixed << setprecision(15) << r * cos(angle[i]) << " " << r * sin(angle[i]) << "\n";
    }
}
