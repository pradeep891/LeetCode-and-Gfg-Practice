class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int , int>mp;
        int id = 0;
        for(auto i : nums){
            int tofind = target - i;
            if(mp.find(tofind) != mp.end()) return {mp[tofind] , id};
            mp[i] = id;
            id++;
        }
        return {};
    }
};