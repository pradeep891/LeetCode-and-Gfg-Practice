//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(vector<int>&arr, int id , int sum , vector< vector<int> >&dp){
        if(sum == 0) return 1;
        
        if(id == 0) return 0;
        
        if(dp[id][sum] != -1) return dp[id][sum];
        
        int pick = 0;
        
        if(sum - arr[id-1] >= 0)
        pick = solve(arr , id-1, sum - arr[id-1] , dp);
        
        int notpick = solve( arr , id -1  , sum , dp);
        
        return dp[id][sum] = pick || notpick;
        // return 0;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector< vector<int> >dp(arr.size()+1 , vector<int>(sum+1 , -1));
        // return false;
        return solve(arr , arr.size() , sum , dp);
        
        // for(int i=0; i<arr.size(); i++)
        // dp[i][0] = 1;
        
        // for(int i=arr.size()-1 ; i>=0 ; i--){
        //     for(int j=1; j<=sum; j++){
        //         int temp = 0;
        //         if(j - arr[i] >=0)
        //         temp = dp[i+1][j - arr[i]];
        //         temp += dp[i+1][j];
                
        //         if(temp >= 1) j = 1;
        //         dp[i][j] = temp;
        //     }
        // }
        // return dp[0][sum];// solve(0 , arr , sum , dp);
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends