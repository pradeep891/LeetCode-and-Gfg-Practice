class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        string ans = "";
        int mxlen = 0;
        
        for(int i=0; i<n ;i++){
            string cur = "";
            map<char , int>mp;
            for(int j=i; j<n ;j++){
                cur.push_back(s[j]);
                mp[s[j]]++;
                
                if(mp[s[j]] > 1)
                    break;
                
                if(mxlen < cur.size()){
                    mxlen = cur.size();
                    ans = cur;
                }
            }
        }
        return mxlen;
    }
};