#include <bits/stdc++.h>
using namespace std;

long long N, M;

int main() {
    cin >> N >> M;
    long long a = N / 3;
    long long b = M / 3;
    long long c = N % 3;
    long long d = M % 3;
    long long ans = 3*a*b + a*d + b*c;
    cout << ans << "\n";
}
