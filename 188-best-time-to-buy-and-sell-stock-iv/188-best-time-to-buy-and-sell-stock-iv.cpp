class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        // vector<vector<vector<int>>>dp(prices.size()+1 , vector<vector<int>>(k+1 , vector<int>(2 , 0)));
        vector<vector<int>> after(k+1 , vector<int>(2 , 0));
        vector<vector<int>> cur(k+1 , vector<int>(2 , 0));
        
        for(int i=prices.size() - 1 ; i>=0; i--){
            for(int j =1; j<=k; j++){
                cur[j][0] = max( -prices[i] + after[j][1] , after[j][0]);
                cur[j][1] = max( prices[i] + after[j-1][0] , after[j][1]);
                after[j] = cur[j];
            }
        }
        return cur[k][0];
    }
};