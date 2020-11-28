// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = rand(2, 10);
    n = 1;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
      int l = rand(1,10000);
      int r = l + rand(0,10000);
      cout << l << ' ' << r << endl;
    }
}
