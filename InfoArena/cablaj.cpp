// OLI 2009, Brasov, grades 11-12
// Cablaj
// https://www.infoarena.ro/problema/cablaj

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int N;
vector<pair<int, int>> arr;

int main() {
	freopen("cablaj.in", "r", stdin);
	freopen("cablaj.out", "w", stdout);
	cin >> N;
	arr.resize(N+1);
	vector<double> key(N+1);
	vector<bool> seen(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i].f >> arr[i].s;
		key[i] = INT_MAX;
		seen[i] = false;
	}
	key[1] = 0;
	for (int i = 1; i < N; i++) {
		double minVal = INT_MAX;
		int minIndex = -1;
		for (int v = 1; v <= N; v++) {
			if (!seen[v] && key[v] < minVal) {
				minVal = key[v];
				minIndex = v;
			}
		}
		int u = minIndex;
		seen[u] = true;
		for (int v = 1; v <= N; v++) {
			double a = (arr[u].f-arr[v].f)*(arr[u].f-arr[v].f);
			double b = (arr[u].s-arr[v].s)*(arr[u].s-arr[v].s);
			double c = sqrt(a+b);
			if (!seen[v] && c < key[v]) {
				key[v] = c;
			}
		}
	}
	double ans = 0;
	for (int i = 1; i <= N; i++) {
		if (key[i] != INT_MAX) {	
			ans += key[i];
		}
	}
	cout << fixed << setprecision(10) << ans << "\n";
}