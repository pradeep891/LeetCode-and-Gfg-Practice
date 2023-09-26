//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>>ans;
        int n = arr.size();
        sort(arr.begin() , arr.end());
        for(int i=0; i<n; i++){
            
            for(int j=i+1; j<n; j++){
                int l = j + 1,  r = n-1;
                int tar = k - arr[i] - arr[j];
                
                while(l < r){
                    int sum = arr[l] + arr[r];
                    if(sum == tar){
                        vector<int>v = {arr[i] , arr[j], arr[l] , arr[r]};
                        ans.push_back(v);
                        while(l < r && arr[l] == v[2]) l++;
                        while(l < r && arr[r] == v[3]) r--;
                    }
                    else if(sum < tar) l++;
                    else r--;
                }
                
                while(j + 1 < n && arr[j] == arr[j + 1]) j++;
            }
            while(i + 1 < n && arr[i] == arr[i+1]) i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends