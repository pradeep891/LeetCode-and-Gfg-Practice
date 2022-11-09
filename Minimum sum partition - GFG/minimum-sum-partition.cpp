//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum  =0;
	    for(int i=0; i<n ;i++) sum += arr[i];
	    
	    vector< vector<int> >dp(n , vector<int>(sum+1 , 0));
        for(int i=n-1 ; i>=0 ; i--)
        dp[i][0] = 1;
        
        dp[0][arr[0]] = 1;
        
        for(int i=1; i<n; i++){
            for(int j=1; j<=sum; j++){
                int pick = 0;
                if(j - arr[i] >= 0)
                pick = dp[i-1][j - arr[i]];
                int notpick = dp[i-1][j];
                
                dp[i][j] = pick | notpick;
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<=sum; i++){
            if(dp[n-1][i] == 0) continue;
    
            int s1 = i;
            int s2 = sum - s1;
            ans = min(ans , abs(s1 - s2));
        }
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends