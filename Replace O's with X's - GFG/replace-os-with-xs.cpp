//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(vector<vector<char>> &mat, int x, int y , int n, int m, queue<pair<int,int>>&q, bool & boundary){
        q.push({x , y});
        mat[x][y] = ' ';
        
        if(x == 0 || x == n-1 || y == 0 || y == m-1) boundary = true;
        int dir[5] = {0,1,0,-1,0};
        for(int i=0; i<4; i++){
            int nx = x + dir[i];
            int ny = y + dir[i+1];
            if(nx >=0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 'O')
            dfs(mat, nx, ny, n, m , q, boundary);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
       for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(mat[i][j] == 'O') {
                    bool boundary = false;
                    queue< pair<int,int> > q;
                    dfs(mat, i, j, n , m, q, boundary);
                    
                    
                    if(boundary == false){
                        while(q.empty() == false)
                        {
                            
                            pair<int,int>ii = q.front();
                            q.pop();
                            int x = ii.first;
                            int y = ii.second;
                            // cout << x << "," << y << " | ";
                            mat[x][y] = 'X';
                        }
                        // cout << endl;
                    }
                   
                }
            }
            
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == ' ') mat[i][j] = 'O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends