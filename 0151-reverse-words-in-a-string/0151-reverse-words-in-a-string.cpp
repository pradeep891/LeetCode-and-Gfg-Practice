class Solution {
public:
    string reverseWords(string s) {
        vector<string>word;
        string cur = "";
        for(auto i : s){
            if(i == ' '){
                if(cur.size())
                word.push_back(cur);
                cur = "";
            }
            else
                cur.push_back(i);
        }        
        if(cur.size())
        word.push_back(cur);
        
        reverse(word.begin() , word.end());
        s = "";
        for(auto i : word){
            s += i;
            s.push_back(' ');
        }
        s.pop_back();
        return s;
    }
};