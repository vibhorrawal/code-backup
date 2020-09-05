// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;


#define MAX 1e5
int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(2, 10);
    printf("%d\n", n);
    set<int> used;
    for(int i = 0; i < n; ++i) {
        int s = rand(1,162);
        int val = rand(1,MAX);
        cout<<val<<' '<<s<<endl;
    }
    puts("");
}
