class Solution {
public:
    string breakPalindrome(string s) {
        int len = s.size();          
        
        for(int i =0; i<len/2 ;i++){
                if(s[i] == 'a') continue;

                s[i] = 'a';
                return s;
        } 
        
        if(len == 1)
        return "";
        
        
        s[len-1] = 'b';
        return s;
        
    }
};