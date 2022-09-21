class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int even = 0;
        for(auto i : nums){
            if(i % 2 == 0) even += i;
        }
        
        vector<int>ans;
        for(auto v : queries){
            int id = v[1];
            int val = v[0];
            int n = nums[id];
            if(n % 2 == 0) even -= n;            
            n = n + val;
            nums[id] = n;
            if(n % 2 == 0) even += n;
            
            ans.push_back(even);
         }
        return ans;
    }
};