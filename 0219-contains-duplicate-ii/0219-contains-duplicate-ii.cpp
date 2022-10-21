class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int , vector<int> >mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        
        for(auto s : mp){
            vector<int>v = s.second;
            for(int i=1; i<v.size(); i++){
                if(v[i] - v[i-1] <= k) return true;
            }
        }
        return false;
    }
};