class Solution {
public:
    
    void dfs(int node , vector<int>&vis , vector<int>&k , vector<int>v[]){
        vis[node] = 1;
        k.push_back(node);
        for(auto i : v[node]){
            if(!vis[i]){
                dfs(i , vis , k , v);
            }
        }
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int>v[26];
        for(auto s : equations){
            int a = s[0] - 'a', b = s[3] - 'a';
    
            if(s[1] == '='){
                v[a].push_back(b);
                v[b].push_back(a);
            }
        }
        
        vector<vector<int>>store;
        vector<int>vis(26,0);
        for(int i=0; i<26; i++){
            if(!vis[i]){
                vector<int>k;
                dfs(i , vis , k , v);
                store.push_back(k);
            }
        }
        vector<int>n(26, 0);
        int ct = 1;
        for(auto i : store){
            for(auto j : i)
                n[j] = ct;
            ct++;
        }
         for(auto s : equations){
            int a = s[0] - 'a', b = s[3] - 'a';
    
            if(s[1] == '!'){
                if(n[a] == n[b]) return false;
            }
        }
        
        return true;
    }
};