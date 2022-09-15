class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        vector<int>a;
        int len = changed.size();
        if(len % 2 == 1) return a;
        len /= 2;
        map<int , int>mp;
        
        for(auto i : changed)
            mp[i]++;
        
        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            int n = it->first;
            int ct = it->second;
            
            if(n == 0){
                if(ct % 2 == 1) return {};
                ct /= 2;
                while(ct--)
                    a.push_back(0);
                return a;
            }
            if(n % 2 == 0 && mp.find(n/2) != mp.end() && mp[n/2] >= ct){
                mp[n/2] -= ct;
                while(ct--) a.push_back(n/2);
                
                if(mp[n/2] == 0) mp.erase(n/2);
            }
            else return {};
        }
        // cout << endl;    
        return a;        
    }
};