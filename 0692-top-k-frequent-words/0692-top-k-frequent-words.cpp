struct cmp{
    bool operator() (pair<int , string> &a , pair<int,  string>&b)  {        
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int>fre;
        for(auto str : words){
            fre[str]++;
        }
        priority_queue< pair<int , string> , vector<pair<int,string> > , cmp>pq;        
        for(auto cur : fre){      
            pq.push({cur.second , cur.first});
            if(pq.size() > k) pq.pop();
        }        
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
        
        
};