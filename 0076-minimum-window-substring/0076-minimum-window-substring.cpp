class Solution {
public:
    
    bool greater_equal(vector<int>&a , vector<int>&b){
        for(int i=0; i<256; i++)
            if(a[i] < b[i]) return false;
        
        return true;
    }
    
    string minWindow(string s, string t) {
        vector<int>T(256, 0) , S(256 , 0);
        for(auto i : s){
            S[i]++;
        }
        for(auto i : t)
            T[i]++;
        
        if(!greater_equal(S , T))
            return "";
        S.clear();
        S.resize(256 , 0);
        
        int i = 0 , j = 0;
        
        int left = 0 , right = s.size()-1;
        int mx = s.size();
        while(i < s.size()){
            S[s[i]]++;
            
            
            while(j<s.size() && greater_equal(S , T)){
                if(mx > i-j+1){
                    left = j;
                    right = i;
                    mx = i-j+1;
                    // cout << left << " " << right << endl;
                }
                S[s[j]]--;
                j++;
            }
            i++;
            
        }
        return s.substr(left , mx);
    }
};