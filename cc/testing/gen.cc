// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

// returns int in range: [a,b]
int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    int seed = argc > 1 ? atoi(argv[1]) : 42;
    srand(seed);
    
    int n = rand(2, 10);
    printf("%d\n", n);
    set<int> used;
    for(int i = 0; i < n; ++i) {
        int x;
        do {
            x = rand(1, 10);
        } while(used.count(x));
        printf("%d ", x);
        used.insert(x);
    }
    puts("");
}
