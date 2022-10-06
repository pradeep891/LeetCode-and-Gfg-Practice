class TimeMap {
public:
    
    
    unordered_map<string , vector< pair<string , int>> >mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {        
        mp[key].push_back({value , timestamp});
    }
    
    string binarysearch(vector< pair<string , int> >&v , int len , int time){
        int i=0 , j=len-1;
        string ans = "";
        while(i<=j){
            int mid = i + (j - i) / 2;
            if(v[mid].second <= time)
            {
                ans = v[mid].first;
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return ans;
    }
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end())
            return "";        
        int len = mp[key].size();        
        return binarysearch(mp[key] , len , timestamp);
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */