class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k != 1){
            sort(s.begin() , s.end()) ;
            return s;
        }
        
        char ch = 'z';
        for(auto i : s)
            ch = min(ch , i);
        string ans = "" ;
        int i=0; 
        while(i < s.size() && s[i] != ch)
            i++;
        ans = s.substr(i) + s.substr(0 , i);
        
        string mn = ans;
        for(int i=0; i<s.size(); i++){
            if(ch == s[i]){
                ans = "" ;
                ans = s.substr(i) + s.substr(0 , i);
                if(mn > ans)
                    mn = ans;
            }
        }
        return mn;
    }
};