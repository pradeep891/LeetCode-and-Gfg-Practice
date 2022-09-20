class Solution {
public:
//     int solve(vector<int>&a , vector<int>&b , int n , int m , vector< vector<int> >&dp){
//         if(n == 0 || m== 0) return 0;
        
//         if(dp[n][m] != - 1) return dp[n][m];
//         int k = max(solve(a , b , n-1 , m , dp) , solve(a , b , n , m-1 , dp));
        
//         if(a[n-1] == b[m-1]){
//             dp[n][m] = 1 + solve(a , b , n-1 , m-1 , dp);
//         }
//         else
//             dp[n][m] = 0;
        
//         return max(dp[n][m] , k);
//     }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        vector< vector<int> >dp(n+1 , vector<int>(m+1 , 0));
        
        int ans = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = 1  + dp[i-1][j-1];
                
                ans = max(ans , dp[i][j]);
            }
        }
        
        return ans;
    }
};