class Solution {
public:
    
    int solve(vector<int>&prices , int i , int k, int buy , vector< vector< vector<int> > > &dp){
        if(k<=0 || i>=prices.size()) return 0;
        
        if(dp[i][k][buy] != -1 ) return dp[i][k][buy];
        
        if(buy == 0) return dp[i][k][buy] = max( -prices[i] + solve(prices , i+1 , k , 1 , dp) , solve(prices , i+1 , k , 0 , dp));
        return dp[i][k][buy] = max( prices[i] + solve(prices , i+1 , k-1 , 0 , dp) , solve(prices , i+1 , k , 1 , dp));
    }
    int maxProfit(vector<int>& prices) {
        vector< vector< vector<int> > > dp(prices.size() + 1 , vector<vector<int>>(2+1 , vector<int>(2 , -1)));
        return solve(prices, 0 , 2 , 0 , dp);
    }
};