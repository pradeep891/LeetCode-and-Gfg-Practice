//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    // bool solve(int ar[], int n , int sum, vector<vector<int>>&dp){
    //     if(sum == 0) return true;
    //     if(sum < 0) return false;
    //     if(n == 0) return false;
        
    //     if(dp[n][sum] != -1) return dp[n][sum];
    //     bool a = solve(ar ,  n-1, sum, dp);
    //     bool b = solve(ar,  n-1 , sum - ar[n-1], dp);
    //     return dp[n][sum] = a || b;
    // }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++) sum += arr[i];
        if(sum % 2 == 1) return 0;
        sum /= 2;
        
        vector<vector<bool>>dp(N+1, vector<bool>(sum+1, false));
        for(int i=1; i<=N; i++){
            for(int j=0; j<=sum; j++){
                if(j == 0) {
                    dp[i][j] = true;
                    continue;
                }
                dp[i][j] = dp[i-1][j];
                if(j-arr[i-1] >= 0) 
                dp[i][j] =  dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
        return dp[N][sum];
        // return solve(arr , N , sum , dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends