class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cur = 0 , ans = 0;
        for(int i=1; i<n; i++){
             cur += prices[i] - prices[i-1];
            ans = max(ans , cur);
            if(cur < 0)  cur = 0;
        }    
        return ans;
    }
};