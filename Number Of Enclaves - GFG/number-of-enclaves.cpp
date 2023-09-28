//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(vector<vector<int>>&grid, int x, int y){
        int n = grid.size();
        int m = grid[0].size();
        if(x < 0 || y < 0 || x == n || y == m) return;
        if(grid[x][y] != 1) return;
        grid[x][y] = 0;
        int dir[5] = {0 , 1 , 0 , -1, 0};
        for(int i=1; i<5; i++){
            int nx = x + dir[i-1];
            int ny = y + dir[i];
            dfs(grid, nx, ny);
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0; i<n; i++) {
            if(grid[i][0] == 1) dfs(grid, i , 0);
            if(grid[i][m-1] == 1) dfs(grid, i, m-1);
        }
        for(int i=0; i<m ; i++){
            if(grid[0][i] == 1) dfs(grid, 0 , i);
            if(grid[n-1][i] == 1) dfs(grid, n-1, i);
        }
        
        int ct =  0;
        for(auto i: grid){
            for(auto j: i) if(j == 1) ct++;
        }
        return ct;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends