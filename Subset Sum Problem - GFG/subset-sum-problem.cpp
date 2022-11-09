//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int id ,vector<int>&arr, int sum , vector< vector<int> >&dp){
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        if(id == arr.size()) return 0;
        
        if(dp[id][sum] != -1) return dp[id][sum];
        
        int pick = solve(id+1 , arr , sum - arr[id] , dp);
        int notpick = solve(id+1 , arr , sum , dp);
        int sum2 = pick + notpick;
        if(sum2 >= 1) 
        sum2 = 1;
        return dp[id][sum] = sum2;
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector< vector<int> >dp(arr.size() , vector<int>(sum+1 , -1));
        return solve(0 , arr , sum , dp);
        
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