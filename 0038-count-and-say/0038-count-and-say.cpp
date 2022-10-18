class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";
        for(int i=2; i<=n; i++)
        {
            string temp = ans;
            ans = "";
            int time = 1;
            int num = temp[0];
            for(int j=1; j<temp.size(); j++){
                if(temp[j] == temp[j-1]){
                    time++;
                }
                else{
                    ans += to_string(time);
                    ans.push_back(num);
                    time = 1;
                    num = temp[j];
                }
            }
            
                    ans += to_string(time);
                    ans.push_back(num);
            
            // cout << ans << " ";
        }
        return ans;
    }
};