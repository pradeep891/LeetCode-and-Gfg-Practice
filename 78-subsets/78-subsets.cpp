class Solution {
public:
    
    void solve(vector<int>&nums , int id , vector<vector<int>>&res , vector<int>&cur){
        int n = nums.size();
        if(id == n) {
            res.push_back(cur);
            return;
        }
        
        solve(nums , id+1 , res , cur);        
        cur.push_back(nums[id]);
        solve(nums , id+1 , res , cur);
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        vector< vector<int>>res;
        // vector<int>vis(nums.size() , 0);
        solve(nums , 0 , res , cur);
        return res;
    }
};