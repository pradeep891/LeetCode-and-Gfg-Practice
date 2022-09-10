class Solution {
public:
    
    int ar[1001][101][2] = {-1};
    int solve(vector<int>&prices , int k ,int id , int bs){
        
        if(id == prices.size() || k == 0)
            return 0;
        // bs == 0 // buy 
        
        if(ar[id][k][bs] != -1)
            return ar[id][k][bs];
        
        int ans = 0;
        if(bs == 0){
            int a = -prices[id] + solve(prices , k , id+1 , 1);
            int b = solve(prices , k , id+1 , bs);
            ans = max(a , b);
        }
        else{            
            int a = prices[id] + solve(prices , k-1 , id+1 , 0);
            int b = solve(prices , k , id+1 , 1);
            ans = max(a , b);
        }
        // return ans;
        return ar[id][k][bs] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        
        for(int i=0; i<1001 ; i++){
        // int i = 0;
            for(int k=0; k<101; k++){
                for(int b = 0; b<2; b++){
                    ar[i][k][b] = -1;
                }
                // cout << endl;
            }
        }
        return solve(prices , k , 0 , 0);
    }
};