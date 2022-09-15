class Solution {
public:
    
    int solve(vector<int>&cost , int i , int n , vector<int>&dp){
        if(i >= n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int a = solve(cost , i+1 , n , dp);
        int b = solve(cost , i+2 , n , dp);
        
        return dp[i] = min(a , b) + cost[i];     
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        vector<int>dp1(n + 4 , -1);
        vector<int>dp2(n + 4 , -1);
        int a = solve(cost , 0 , n , dp1);
        int b = solve(cost , 1 , n , dp2);
        return min(a , b);
    }
};