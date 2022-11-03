class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int sz = 0;
        map<string , int > mp;
        map<string , int>equal;
        for(int i=0; i<words.size(); i++){
            string s = words[i];
            string rev = s;
            reverse(rev.begin(), rev.end());
            
            if(s[0] == rev[0] ){
                equal[s]++; 
                continue;
            }
            
            if(mp.find(rev) != mp.end()) // element present
            {
                sz += 4;
                if(mp[rev] != 1)
                    mp[rev]--;
                else
                    mp.erase(rev);
            }
            else
                mp[s]++;
        }
        
        int fl = 0;
        for(auto i : equal){
            if(i.second % 2)
                 fl = 1;
            
            sz += (i.second/2) * 4;
        }
        if(fl)
            sz+=2;
        return sz;
            
        
        
    }
};