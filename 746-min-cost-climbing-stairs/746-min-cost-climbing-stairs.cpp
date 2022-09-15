class Solution {
public:
    
    int solve(vector<int>&cost , int i , int n , vector<int>&dp){
        if(i >= n) return 0;
        
        if(dp[i+1] != -1) return dp[i+1];
        
        int a = solve(cost , i+1 , n , dp);
        int b = solve(cost , i+2 , n , dp);
        
        if(i == -1)
        return dp[i+1] = min(a , b);
        else
        return dp[i+1] = min(a , b) + cost[i];     
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int>dp(n + 4 , -1);
        int a = solve(cost , -1 , n , dp);
        // int b = solve(cost , 1 , n , dp2);
        return a;
    }
};