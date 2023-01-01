//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	int power(long long a , long long b  , long long mod){
	    long long res = 1;
	    while(b){
	        if(b % 2 == 0){
	            a = (a * a) % mod;
	            b /= 2;
	        }
	        else{
	            res = (res * a) % mod;
	            b--;
	        }
	    }
	    return res;
	}
	int C(int n , int r){
	    long long mod = 1e9+7;
	    long long res = 1;
	    for(int i=r+1; i<=n; i++){
	        res = (res * i) % mod;
	    }
	    
	    for(int i=2; i<=r; i++){
	        res = (res * power(i , mod-2 , mod)) % mod;
	    }
	    return res;
	}
	int compute_value(int n)
	{
	    // Code here
	    return C(2*n , n);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends