class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int i=1;
        vector<int>v;
        v.push_back(neededTime[0]);
        while(i < colors.size())
        {
            if(colors[i] == colors[i-1]){
                v.push_back(neededTime[i]);
                i++;
            }   
            else{
                sort(v.begin() , v.end());
                for(int j=0; j<v.size()-1; j++)
                    ans += v[j];
                
                v.clear();
                v.push_back(neededTime[i]);
                i++;
            }
        }
        
        if(v.size() > 1){
             sort(v.begin() , v.end());
                for(int j=0; j<v.size()-1; j++)
                    ans += v[j];
                
        }
        
        return ans;
    }
};