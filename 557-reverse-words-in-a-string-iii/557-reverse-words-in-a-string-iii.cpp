class Solution {
public:
    
    void change(string &s , int i , int j){
        // j--;
        
        while(i<j){
            swap(s[i++] , s[j--]);
        }
    }
    string reverseWords(string s) {
        int len = s.size();
        int i=0 , j =0;
        while(i<len){
            j=i;
            while(j<len){
                if(s[j] == ' '){
                    break;
                }
                j++;
            }
            
            change(s , i , j-1);
            i = j+1;
        }
        
        change(s , i , j-1);
        
        return s;
    }
};