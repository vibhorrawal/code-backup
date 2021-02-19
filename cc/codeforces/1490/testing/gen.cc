// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    int seed = argc > 1 ? atoi(argv[1]) : 42;
    srand(seed);
    int t = 100;
    printf("%d\n", t);
    int sz = 100;
    while(t--){
        int n = rand(1, sz);
        printf("%d\n", n);
        set<int> used;
        for(int i = 0; i < n; ++i) {
            int x;
            do {
                x = rand(1, sz  );
            } while(used.count(x));
            printf("%d ", x);
            used.insert(x);
        }
        puts("");
    }
}
