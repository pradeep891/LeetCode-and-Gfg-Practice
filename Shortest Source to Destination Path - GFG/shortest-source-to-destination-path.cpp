//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        queue<pair<int,int>>q;
        
        q.push({0 , 0});
        
        int ct = -1;
        A[0][0] = 0;
        while(q.empty() == false){
            int sz = q.size();
            ct++;
            for(int i=0; i<sz; i++){
                int x = q.front().first, y = q.front().second;
                q.pop();
                
                if(x == X && y == Y) return ct;
                
                
                int dir[] = {0 , 1 , 0 , -1, 0 };
                for(int j=0; j<4; j++){
                    int nx = x + dir[j], ny = y + dir[j+1];
                    if(nx < N && nx >=0 && ny >=0 && ny < M && A[nx][ny] == 1){
                        A[nx][ny] = 0;
                        q.push({nx,ny});
                    }
                }
                
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends