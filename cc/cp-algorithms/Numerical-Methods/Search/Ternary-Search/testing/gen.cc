// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int max = 1e1;
    int n = rand(1,max);
    int k = rand(1,max);
    printf("%d %d\n", n, k);
    for(int i = 0; i < n; ++i) {
        int s = rand(1,max);
        int d = rand(0,max);
        printf("%d %d", s, d);
    }
    puts("");
}
