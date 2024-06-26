#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    cout << N << " " << M << endl;
    for (int i = 1; i <= N; i++) {
        cout << rnd.next(-1, 1);
        if (i < N) cout << " ";
        else cout << endl;
    }
    vector<set<int>> s(N+1);
    for (int i = 1; i <= M; i++) {
        int u = rnd.next(1, N);
        int v = rnd.next(1, M);
        while ((s[u].find(v) != s[u].end()) && (s[v].find(u) != s[v].end())) {
            v = rnd.next(1, M);
        }
        s[u].insert(v);
        s[v].insert(u);
        cout << u << " " << v << endl;
    }
}