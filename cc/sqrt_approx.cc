#include <bits/stdc++.h>
using namespace std;

float sqrt2(float n){
	float ans;
	int start = 0, end = n;
	int mid;
	while (start <= end) { 
        mid = (start + end) / 2; 
        if (mid * mid == n) { 
            ans = mid; 
            break; 
        }

        if(mid*mid < n){
        	start = mid +1;
        	ans = mid;
    	}

    	else{
    		end = mid - 1;
    		// ans = mid;
    	}
    }
    // cout<<ans<<endl;
    float increment = 0.1;
    for (int i = 0; i < 5; ++i)
    {
    	while(ans*ans < n)
    		ans+= increment;
    	ans -= increment;
    	increment /= 10;
    }
    return ans;
}
int main(int argc, char const *argv[])
{
	float n;
	cin>>n;
	// n = 3;
	cout<<sqrt2(n);
	return 0;
}