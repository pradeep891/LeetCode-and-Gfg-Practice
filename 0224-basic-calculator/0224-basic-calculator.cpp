class Solution {
public:
    
    string solve(string s){
        //remomve space
        string k = "";
        for(auto i : s){
            if(i != ' ') k.push_back(i);
        }
        
        // cout << "k " << k << endl;
        
        int i=0;
        s = "";
        while(i < k.size()){
            if(k[i] == '-'){
                if(k[i+1] == '-'){
                    s.push_back('+');
                    i++;
                }
                else
                    s.push_back('-');
                i++;
            }
            else if(k[i] == '+'){
                if(k[i+1] == '-'){
                    s.push_back('-');
                    i++;
                }
                else
                    s.push_back('+');
                i++;
            }
            
            else {
                string num = "";
                while(i <k.size() && (k[i] != '-' && k[i] != '+')){
                num += k[i];
                i++;
                }
                s += num;
            }
        }
        
        // cout << "s = " << s << " ";
        int ans  = 0;
        i = 0;
        while(i < s.size()){
            int sign = 1;
            if(s[i] == '+') i++;
            else if(s[i] == '-'){
                sign = -1;
                i++;
            }
            string num = "";
            while(i<s.size() && (s[i] != '-' && s[i] != '+')){
                num += s[i];
                i++;
            }
            // cout << "num = " << num << endl;
            ans += sign * stoi(num);
        }
        return to_string(ans);
    }
    int calculate(string s) {
        string cur = "";
        stack<string>st;
        for(int i=0 ; i<s.size(); i++){
            if(s[i] == '('){
                if(cur.size())
                st.push(cur);
                cur = "";
            }
            else if(s[i] == ')'){
                // solve the expression
                string k = solve(cur);
                if(st.empty() ==false){        
                    cur = st.top();            
                    st.pop();
                }
                else
                    cur = "";
                cur += k;
            }
            else{
                cur += s[i];
            }
        }
        string k = solve(cur);
        return stoi(k);
    }
};