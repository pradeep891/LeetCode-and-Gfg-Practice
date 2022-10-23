class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int>mp;
        int dup;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] == 2) dup = nums[i];
            sum += nums[i] - (i+1);
        }
        return {dup , abs(sum - dup)};
    }
};