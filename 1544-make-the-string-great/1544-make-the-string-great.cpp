class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto i : s){
            if(st.empty()){
                st.push(i);
                continue;
            }
            
            int top = st.top();
            if(top != i && tolower(top) - 'a' == tolower(i) - 'a'){
                st.pop();
            }
            else
                st.push(i);
        }
        s = "";
        while(!st.empty()){
            s += st.top();
            st.pop();
        }
        reverse(s.begin() , s.end());
        return s;
    }
};