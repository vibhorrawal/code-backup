// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = 5, m = rand(0, n);
    cout << n << ' ' << n-1 << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ' ';
    }
    cout<<endl;
    for(int i = 2; i <= n; ++i) {
        printf("%d %d\n", rand(1, i - 1), i);
    }
    cout<<n<<endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ' ';
    }
    cout<<endl;
    cout<<"0 0";
}
