class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int i=0;
        while(i < s.size()){
            while(st.empty() == false && i<s.size() && st.top() == s[i])
                st.pop() , i++;
            
            if(i<s.size())
            st.push(s[i++]);
        }
        
        string ans = "";
        while(st.empty() == false){
            ans += st.top();
            st.pop();
            
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};