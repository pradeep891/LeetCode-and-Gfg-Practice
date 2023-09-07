//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int solve(int ct ,vector<int>&arr, int start, int end, map<int,int>&mp, int mod){
      int mn = INT_MAX;
      if(mp.find(start) != mp.end())  return mn;
      mp[start] = 1;
      
      if(start == end){
          return ct;
      }
      
      cout << start << " | ";
      
      for(auto i : arr){
          int newstart =  (i * start) % mod;
          int temp = solve(1 + ct, arr, newstart, end, mp, mod);
          mn = min(temp , mn);
      }
      
      return mn;
  }
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        queue<int>q;
        q.push(start);
        int mod = 100000;
        vector<int>vis(mod, 0);
        vis[start] = 1;
        
        
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int node = q.front();
                q.pop();
                if(node == end) return ans;
                
                for(auto id: arr) {
                    start = id * node;
                    start %= mod;
                    if(vis[start] == 0){
                        vis[start] = 1;
                        q.push(start);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends