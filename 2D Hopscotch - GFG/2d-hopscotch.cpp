//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int find(int n , int m , vector<vector<int>> &mat,  vector<vector<int>> &vis,int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= m) return 0;
        else if(vis[i][j] == 1)  return 0;
        vis[i][j] = 1;
        return mat[i][j];
    }
    int solve(int n , int m , vector<vector<int>> &mat, vector<vector<int>> &vis, int i, int j){
        // vis[i][j] = 1;
        int ans = 0;
        ans += find(n , m , mat ,vis, i+1 , j);
        ans += find(n , m , mat ,vis, i-1 , j);
        ans += find(n , m , mat ,vis, i , j+1);
        ans += find(n , m , mat ,vis, i , j-1);
        
        if(j % 2 == 1){
            ans += find(n , m , mat ,vis, i+1 , j-1);
            ans += find(n , m , mat ,vis, i+1 , j+1);
        }
        
        else{
            ans += find(n , m , mat ,vis, i-1 , j-1);
            ans += find(n , m , mat ,vis, i-1 , j+1);
        }
        return ans;
    }
    
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        // code here
        vector<vector<int>>vis(n , vector<int>(m , 0));
        if(ty == 0)
        return solve(n , m , mat ,vis, i , j);
        
        vis[i][j] = 1;
        if(i+1 < n) vis[i+1][j] = 1;
        if(i-1 >= 0) vis[i-1][j] = 1;
        if(j+1 < m) vis[i][j+1] = 1;
        if(j -1 >= 0) vis[i][j-1] = 1;
        
        if(j % 2 == 1){
            if(i+1 < n && j-1>=0) vis[i+1][j-1] = 1;
            if(i+1 < n && j+1 <m) vis[i+1][j+1] = 1;
        }
        else{
            if(i-1>=0 && j-1>=0) vis[i-1][j-1] = 1;
            if(i-1>=0 && j+1<m) vis[i-1][j+1] = 1;
        }
        
        int ans = 0;
        ans += solve(n , m , mat , vis , i+1 , j);
        ans += solve(n , m , mat , vis , i-1 , j);
        ans += solve(n , m , mat , vis , i , j+1);
        ans += solve(n , m , mat , vis , i , j-1);
        
        if(j % 2 == 1){
            ans += solve(n , m , mat , vis , i+1 , j-1);
            ans += solve(n , m , mat , vis , i+1 , j+1);
        }
        
        else{
            ans += solve(n , m , mat , vis , i-1 , j-1);
            ans += solve(n , m , mat , vis , i-1 , j+1);
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends