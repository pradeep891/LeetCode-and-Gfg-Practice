class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0; i<s.size(); i+=2*k){
            int r=i+k-1 , l=i;
            r = min(r , (int)s.size() - 1);
            while(l < r)
                swap(s[l++] , s[r--]);
        }
        return s;        
    }
};