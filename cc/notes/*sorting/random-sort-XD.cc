#include<bits/stdc++.h>

using namespace std;

bool is_sorted(vector<int> &a) {
    for(int i = 1; i < a.size(); i++) 
        if(a[i-1] > a[i]) 
            return false;
    return true;
}

// O(n!) time | O(1) space
void random_sort(vector<int> &a) {
    const int n = a.size();
    while(!is_sorted(a)) {
        int idx1 = rand() % n;
        int idx2 = (idx1 + (rand() % (n - idx1 + 1))) % n;
        swap(a[idx1], a[idx2]);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4,5,3,1,2,-10,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> a(arr, arr + n);
    random_sort(a);
    for(int i : a) cout<<i<<' ';
    return 0;
}
