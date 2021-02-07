// generating a random sequence of distinct elements
#include <bits/stdc++.h>
#define endl char(10)
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int nn = rand(1, 100);
    nn = 10;
    printf("%d\n", nn);
    for(int i = 0; i < nn; ++i) {
        int n = rand(5, 10000);
        int k = rand(0, n-1);
        int m = rand(1, (n * (n - 1) / 2) - 1);
        m = n * sqrt(n);
        cout << n << ' ' << k <<' ' << m << endl;
        set<pair<int,int>> s;
        for (int j = 0; j < m; j++) {
            int u, v, w;
            do {
                u = rand(0, n-1);
                v = rand(0, n-1);
                w = rand(0, 1e3);
                if(u == v) continue;
            } while(s.count({u, v}));
            cout << u << ' ' << v << ' ' << w << endl;
        }
    }
    puts("");
}
