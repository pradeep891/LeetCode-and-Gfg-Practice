class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        string ans = "";
        
        int times = 1;
        char ch = chars[0];
        for(int i=1; i<len ; i++){
            if(chars[i-1] == chars[i]){
                times++;
            }
            else{
                ans.push_back(ch);
                if(times > 1)
                    ans += to_string(times);
                ch = chars[i];
                times = 1;
            }
            
        }
        
                ans.push_back(ch);
                if(times > 1)
                    ans += to_string(times);
        
        int id = 0;
        for(auto i : ans){
            chars[id] = i;
            id++;
        }
        return ans.size();
    }
};