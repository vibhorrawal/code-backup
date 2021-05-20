#include <bits/stdc++.h>
using namespace std;

#define int long long

bool cached;

int getSum(int BITree[], int index)
{
	int sum = 0;
	while (index > 0) {
		sum += BITree[index];
		index -= index & (-index);
	}
	return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{
	while (index <= n) {
		BITree[index] += val;
		index += index & (-index);
	}
}

void convert(int arr[], int n)
{
	int temp[n];
	for (int i = 0; i < n; i++)
		temp[i] = arr[i];
	sort(temp, temp + n);

	for (int i = 0; i < n; i++) {

		arr[i] = lower_bound(temp, temp + n,
						arr[i]) - temp + 1;
	}
}

int getInvCount(int arr[], int k, int n)
{
	int invcount = 0;
    if(!cached)
	convert(arr, n);
    cached = true;
	int BIT[n + 1];
	for (int i = 1; i <= n; i++)
		BIT[i] = 0;

	for (int i = k - 1; i >= 0; i--) {

		invcount += getSum(BIT, arr[i] - 1);

		updateBIT(BIT, n, arr[i], 1);
	}

	int ans = invcount;
	int i = 0, j = k, icnt = 0, jcnt = 0;
	while (j <= n - 1) {

		icnt = getSum(BIT, arr[i] - 1);
		updateBIT(BIT, n, arr[i], -1);

		jcnt = getSum(BIT, n) - getSum(BIT, arr[j]);
		updateBIT(BIT, n, arr[j], 1);

		invcount = invcount - icnt + jcnt;

		ans = ans + invcount;
		i++, j++;
	}
	return ans;
}
int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        cached = false;

        int n, mod;
        cin>>n>>mod;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += getInvCount(arr, i, n);
        }
        cout << ans % mod << endl;
        // cached = false;
    }
	return 0;
}
