// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int T = rand(1, 100);
    printf("%d\n", T);
    for (int i = 0; i < T; i++) {
      int n = rand(1,5);
      int c = rand(1,n);
      int a = rand(c,n);
      int b = rand(c,n);
      std::cerr << "/* error message */" << '\n';
      cout << n<<' '<<a<<' '<<b<<' '<<c << endl;
    }
}
