class Solution {
public:
    
    int solve(vector<int>&num , int l , vector<int>&mul , int id , vector< vector<int> >&dp){
        if(id == mul.size()) return 0;
        
        if(dp[l][id] != INT_MIN) return dp[l][id];
        
        int r = num.size() - (id - l) - 1;
        int left = mul[id] * num[l] + solve(num , l+1 ,  mul , id+1 , dp);
        int right = mul[id] * num[r] + solve(num , l , mul , id+1 , dp);
        return dp[l][id] = max(left , right);        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        int m = multipliers.size();
        vector< vector<int> >dp(m+1 , vector<int>(m + 1 , INT_MIN));
//         vector< vector<int> >front(nums.size()+1 , vector<int>(nums.size() + 1 , 0));
        
//         for(int i=multipliers.size()-1 ; i>=0; i--){
//             int left = multipliers[i] * (long)nums[l] + front[l+1][r];            
//             int right = multipliers[i] * (long)nums[r] + front[l][r-1];            
//             cur[l][r] = max(left , right);
//             front = cur;
//         }
        
        return solve(nums , 0 , multipliers , 0 , dp);
    }
};