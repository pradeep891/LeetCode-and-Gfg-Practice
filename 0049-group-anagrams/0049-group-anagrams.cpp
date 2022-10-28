class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string , vector<string> > mp;
        for(auto i : strs){
            string st = i;
            sort(st.begin() , st.end());
            mp[st].push_back(i);
        }
        
        vector<vector<string>> ans;
        for(auto i : mp)
            ans.push_back(i.second);
        
        return ans;
    }
};