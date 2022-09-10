class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        vector< vector< vector<int> > > dp(prices.size() + 1 , vector<vector<int>>(2+1 , vector<int>(2 , 0)));
        for(int i=prices.size() - 1 ; i>=0; i--){
            for(int j=1; j<=2; j++){
                
                        dp[i][j][0] = max( -prices[i] + dp[i+1][j][1] , dp[i+1][j][0] );
                        dp[i][j][1] = max( prices[i] + dp[i+1][j-1][0] , dp[i+1][j][1] );  
                
            }
        }
        return dp[0][2][0]; //solve(prices, 0 , 2 , 0 , dp);
    }
};