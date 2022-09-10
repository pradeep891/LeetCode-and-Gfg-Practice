class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        vector< vector<int> > front(2+1 , vector<int>(2 , 0));        
        vector< vector<int> > cur(2+1 , vector<int>(2 , 0));
        
        for(int i=prices.size() - 1 ; i>=0; i--){
            for(int j=1; j<=2; j++){
                
                        cur[j][0] = max( -prices[i] + front[j][1] , front[j][0] );
                        cur[j][1] = max( prices[i] + front[j-1][0] , front[j][1] );  
                front[j] = cur[j];
            }
        }
        return front[2][0]; //solve(prices, 0 , 2 , 0 , dp);
    }
};