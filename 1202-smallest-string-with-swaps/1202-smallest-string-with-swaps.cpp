class Solution {
public:
    
    void dfs(int node , vector<int>&vis , vector<int>adj[] , vector<int>&v){
        if(vis[node] == 1) return;
        
        vis[node] = 1;
        v.push_back(node);
        for(auto i : adj[node]){
            dfs(i , vis , adj , v);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.size();
        vector<int>adj[len];
        
        for(auto i : pairs){
            int u = i[0] , v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>vis(len , 0);
        
        
        vector<int>v;        
        for(int i=0; i<len ; i++){
            if(vis[i] == 1) 
                continue;
            
            dfs(i, vis, adj , v);
            string k = "";
            for(auto j : v)
                k.push_back(s[j]);
            
            sort(v.begin() , v.end());
            sort(k.begin() , k.end());
            int id = 0;
            for(auto j : v){
                s[j] = k[id];
                id++;
            }
            v.clear();
        }
        
        return s;
    }
};