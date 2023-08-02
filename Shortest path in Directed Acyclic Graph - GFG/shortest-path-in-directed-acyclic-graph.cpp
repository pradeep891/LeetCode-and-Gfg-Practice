//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(auto i : edges){
            int u = i[0] , v = i[1] , w = i[2];
            adj[u].push_back({v,w});
        }
        
        vector<int>dis(N,INT_MAX);
        dis[0] = 0;
        
        queue< pair<int,int> >q;
        q.push({0 , 0});
        
        while(q.empty() == false){
            int node = q.front().first, w = q.front().second;
            q.pop();
            
            for(auto i : adj[node]){
                if(w + i.second < dis[i.first]){
                    dis[i.first] = w + i.second;
                    q.push({i.first, dis[i.first]});
                }
            }
        }
        
        for(int i=0; i<N ;i++) if(dis[i] == INT_MAX) dis[i] = -1;
        
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends