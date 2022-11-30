class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int>mp;
        for(auto i : arr) mp[i]++;
        
        map<int , int>mp2;
        for(auto i : mp){
            mp2[i.second]++;
            if(mp2[i.second] > 1) return false;
        }
        return true;
    }
};