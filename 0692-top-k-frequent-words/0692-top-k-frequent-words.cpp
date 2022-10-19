class Solution {
public:
    bool static cmp(pair<int , string> &a , pair<int,  string>&b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int>fre;
        for(auto str : words){
            fre[str]++;
        }
        // priority_queue< pair<int , string> , vector<pair<int,int> > , cmp>pq;
        
        vector< pair<int , string>> v;
        for(auto i : fre){
            v.push_back({i.second , i.first});
//             if(pq.size() <= k){
//                 pq.push({i.second , i.first});
//             }
            
//             else{
//                 int f = i.first;
//                 string str = i.second;
//                 pair<string , int>top = pq.top();
//                 if(f < top.second)
//                     continue;
                
//                 // pq.pop();
//                 if(f == top.second){
                    
//                 }
                
//             }
        }
        
        sort(v.begin()  , v.end() , cmp);
        vector<string>ans;
        for(int i=0; i<k ;i++)
            ans.push_back(v[i].second);
        return ans;
    }
        
        
};