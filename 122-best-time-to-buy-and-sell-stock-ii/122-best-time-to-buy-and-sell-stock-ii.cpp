class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size()+1 , vector<int>(2 , 0));
        vector<int>front(2 , 0) , cur(2 , 0);
        for(int i=prices.size() -1 ; i>=0 ; i--){
            for(int j=0; j<2; j++){
                if(j == 0)
                    cur[j] = max( -prices[i] + front[1] , front[0]);
                else
                    cur[j] = max( prices[i] + front[0] , front[1]);
            }
            front = cur;            
        }
        return cur[0];
    }
};