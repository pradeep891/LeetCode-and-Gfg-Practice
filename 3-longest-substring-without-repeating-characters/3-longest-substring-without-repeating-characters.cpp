class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // string ans = "";
        int mxlen = 0;
        vector<int>v(256 , -1);
        int left = 0;
        
        for(int i=0; i<n ;i++){
            char ch = s[i];
            
            if(v[ch] != -1){
                int id = v[ch];
                for(int j=left; j<=id; j++){
                    v[s[j]] = -1;
                }            
                left = id+1;
            }
            v[ch] = i;
            mxlen = max(mxlen , i - left + 1);            
        }
        return mxlen;
    }
};