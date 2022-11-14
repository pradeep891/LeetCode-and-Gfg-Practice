class Solution {
public:
    void dfs(map< pair<int , int > , int >&vis , vector<int>row[] , vector<int>col[] , int x , int y){
        
        for(auto i : row[x]){
            if(vis[{x , i}] == 0){
                vis[{x , i}] = 1;
                dfs(vis , row , col , x , i);
            }
        }
        
        for(auto i : col[y]){
            if(vis[{i , y}] == 0){
                vis[{i , y}] = 1;
                dfs(vis , row , col , i , y);
            }
        }
        
    }
    int removeStones(vector<vector<int>>& stones) {
        map< pair<int , int > , int > vis;
        int n = 1e4 + 2;
        vector<int>row[n] , col[n];
        
        for(auto i : stones){
            int x = i[0] , y = i[1];
            vis[{x , y}] = 0;
            row[x].push_back(y);
            col[y].push_back(x);
        }
        
        int ct = 0;
        for(auto i : stones){            
            int x = i[0] , y = i[1];
            if(vis[{x , y}] == 1) continue;
            vis[{x , y}] = 1;
            dfs(vis , row , col , x , y);
            ct++;
        }
    
        return stones.size() - ct;
    }
};