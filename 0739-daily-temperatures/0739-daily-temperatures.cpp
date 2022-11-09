class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack< pair<int ,  int> >st;
        for(int i=temp.size()-1 ; i>=0 ; i--){
            
            while(st.empty() == false && st.top().first <= temp[i]){
                st.pop();
            }
            int ans = 0;
            if(!st.empty())
                ans = st.top().second - i;
            
            st.push({temp[i] , i});
            temp[i] = ans;
        }
        return temp;
    }
};