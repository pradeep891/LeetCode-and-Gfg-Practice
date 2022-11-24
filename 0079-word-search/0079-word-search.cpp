class Solution {
public:
    
    bool dfs(int x , int y , vector<vector<int>>&vis , vector<vector<char>>&board , string word , int id){
        // if(board[i][])
        
        int n  = board.size();
        int m = board[0].size();
        
        if(id == word.size()) return true;
        if(x >= n || x < 0 || y < 0 || y >= m )return false;
        if(vis[x][y] == 1) return false;
        if(board[x][y] != word[id]) return false;
        
        vis[x][y] = 1;
        
        if(dfs(x+1 , y , vis , board , word , id+1)) return true;
        if(dfs(x-1 , y , vis , board , word , id+1)) return true;
        if(dfs(x , y+1 , vis , board , word , id+1)) return true;
        if(dfs(x , y-1 , vis , board , word , id+1)) return true;
        
        vis[x][y] = 0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n  = board.size();
        int m = board[0].size();
        
        vector<vector<int>>vis(n , vector<int>(m , 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i , j , vis , board , word , 0)) return true;
                }
            }
        }
        return false;
    }
};