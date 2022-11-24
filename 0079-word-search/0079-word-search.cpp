class Solution {
public:
    
    bool dfs(int x , int y , vector<vector<char>>&board , string word , int id){
        // if(board[i][])
        
        int n  = board.size();
        int m = board[0].size();
        
        if(id == word.size()) return true;
        if(x >= n || x < 0 || y < 0 || y >= m )return false;
        if(board[x][y] == '.') return false;
        if(board[x][y] != word[id]) return false;
        
        char ch = board[x][y];
        board[x][y] = '.';
        
        if(dfs(x+1 , y , board , word , id+1)) return true;
        if(dfs(x-1 , y , board , word , id+1)) return true;
        if(dfs(x , y+1 , board , word , id+1)) return true;
        if(dfs(x , y-1 , board , word , id+1)) return true;
        
        board[x][y] = ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n  = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(dfs(i , j , board , word , 0)) return true;
                }
            }
        }
        return false;
    }
};