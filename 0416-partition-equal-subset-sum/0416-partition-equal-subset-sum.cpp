class Solution {
public:
    
      int solve(int id ,vector<int>&arr, int sum , vector< vector<int> >&dp){
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        if(id == arr.size()) return 0;
        
        if(dp[id][sum] != -1) return dp[id][sum];
        
        int pick = solve(id+1 , arr , sum - arr[id] , dp);
        int notpick = solve(id+1 , arr , sum , dp);
        int sum2 = pick + notpick;
        if(sum2 >= 1) 
        sum2 = 1;
        return dp[id][sum] = sum2;
    }
    bool canPartition(vector<int>& nums) {
        int sum  =0;
        for(auto i : nums) sum += i;
        
        if(sum % 2) return false;
        
        vector< vector<int> >dp(nums.size() , vector<int>(sum/2+1 , -1));
        return solve(0 , nums , sum/2 , dp);
    }
};