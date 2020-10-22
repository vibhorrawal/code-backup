// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int w = rand(1,1000);
    int n = rand(2, 1000);
    printf("%d\n%d %d\n", 1,w,n);
    for(int i = 0; i < w; ++i) {
        int x = rand(1,n);
        printf("%d ", x);
    }
    puts("");
}
