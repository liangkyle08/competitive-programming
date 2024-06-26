#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const int MOD = 1e9+7;

struct Oper {
    char T;
    int L, R, X;
};

int N, M;
long long hSegTree[4000001];
long long vSegTree[4000001];

void hUpdate(int node, int L, int R, int pos, int val) {
    if (L == R) {
        hSegTree[node] = val;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid) {
        hUpdate(2*node, L, mid, pos, val);
    }
    else {
        hUpdate(2*node+1, mid+1, R, pos, val);
    }
    hSegTree[node] = hSegTree[2*node]+hSegTree[2*node+1];
}

long long hQuery(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return 0LL;
    }
    if (Lq <= L && R <= Rq) {
        return hSegTree[node];
    }
    int mid = (L + R) / 2;
    return hQuery(2*node, L, mid, Lq, Rq)+hQuery(2*node+1, mid+1, R, Lq, Rq);
}

void vUpdate(int node, int L, int R, int pos, int val) {
    if (L == R) {
        vSegTree[node] = val;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid) {
        vUpdate(2*node, L, mid, pos, val);
    }
    else {
        vUpdate(2*node+1, mid+1, R, pos, val);
    }
    vSegTree[node] = vSegTree[2*node]+vSegTree[2*node+1];
}

long long vQuery(int node, int L, int R, int Lq, int Rq) {
    if (R < Lq || L > Rq) {
        return 0LL;
    }
    if (Lq <= L && R <= Rq) {
        return vSegTree[node];
    }
    int mid = (L + R) / 2;
    return vQuery(2*node, L, mid, Lq, Rq)+vQuery(2*node+1, mid+1, R, Lq, Rq);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen(".in", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> N >> M;
    vector<Oper> arr(M);
    for (int i = 0; i < M; i++) {
        cin >> arr[i].T >> arr[i].L >> arr[i].R >> arr[i].X;
    }
    reverse(arr.begin(), arr.end());
    map<int, long long> ans;
    for (auto [T, L, R, X]: arr) {
        long long hLeft, hRight, vLeft, vRight;
        if (T == 'H') {
            hLeft = L;
            hRight = R;
            vLeft = 1;
            vRight = N;
        }
        else {
            hLeft = 1;
            hRight = N;
            vLeft = L;
            vRight = R;
        }
        long long A = hQuery(1, 1, N, hRight, hLeft)*(vRight-vLeft+1);
        long long B = vQuery(1, 1, N, vRight, vLeft)*(hRight-hLeft+1);
        long long C = hQuery(1, 1, N, hRight, hLeft)*vQuery(1, 1, N, vRight, vLeft);
        long long area = (hRight-hLeft+1)*(vRight-vLeft+1)-A-B+C;
        ans[X] += area;
        cout << X << " " << area << "\n";
        cout << A << " " << B << " " << C << "\n";
        if (T == 'H') {
            hUpdate(1, 1, N, L, 1);
            hUpdate(1, 1, N, R+1, -1);
        }
        else {
            vUpdate(1, 1, N, L, 1);
            vUpdate(1, 1, N, R+1, -1);
        }
    }
    long long mn = (1LL<<60);
    long long mx = -(1LL<<60);
    for (auto [u, v]: ans) {
        mn = min(mn, v);
        mx = max(mx, v);
    }
    cout << mn << " " << mx << "\n";
}
