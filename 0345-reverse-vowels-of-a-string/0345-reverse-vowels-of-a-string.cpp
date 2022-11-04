class Solution {
public:
    
    bool vowel(char ch){
        string s = "AaEeIiOoUu";
        for(auto i : s){
            if(i == ch)
                return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int i=0 , j=s.size() - 1;
        while(i < j){
            // cout << "\n " << i << ", " << j << " | ";
            if(vowel(s[i]) && vowel(s[j])){
                // cout << "A";
                swap(s[i] , s[j]);
                i++;
                j--;
            }
            else if(vowel(s[j]))
                i++;
            else if(vowel(s[i]))
                j--;
            
            else{
                i++;
                j--;
            }
        }
        
        return s;
    }
};