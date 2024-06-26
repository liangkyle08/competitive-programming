#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int N = atoi(argv[1]);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << rnd.next("A|B|.");
        } cout << endl;
    }

}