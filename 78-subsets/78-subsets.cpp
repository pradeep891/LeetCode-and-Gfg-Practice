class Solution {
public:
    
//     void solve(vector<int>&nums , int id , vector<vector<int>>&res , vector<int>&cur){
//         int n = nums.size();
//         if(id == n) {
//             res.push_back(cur);
//             return;
//         }
        
//         solve(nums , id+1 , res , cur);        
//         cur.push_back(nums[id]);
//         solve(nums , id+1 , res , cur);
//         cur.pop_back();
//     }
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        int n = pow(2, len);
        
        vector< vector<int>>res;
        // cout << "n = " << n << endl;
        for(int i=0; i<n ;i++){
            // cout << i <<  " ";
            int k = i;
            vector<int>cur;
            for(int j=0; j<len; j++){
                
                int p = 1 << (len-j-1);
                int r = k & p;
                // cout << p << " " <<  r << " | ";
                if(r & p)
                    cur.push_back(nums[j]);
            }
            // cout << endl;
            res.push_back(cur);
        }
        // vector<int>cur;
        // vector< vector<int>>res;
        // // vector<int>vis(nums.size() , 0);
        // solve(nums , 0 , res , cur);
        return res;
    }
};