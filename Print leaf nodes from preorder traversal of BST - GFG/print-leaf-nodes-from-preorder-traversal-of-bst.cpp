//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    void solve(int arr[] , int l , int r , vector<int>&leaf){
        if(l > r) return;
        
        if(l == r) {
            leaf.push_back(arr[l]);
            return;
        }
        
        int i=l;
        for(i=l+1; i<=r ; i++){
            if(arr[i] > arr[l]){
                break;
            }
        }
        solve(arr , l+1 , i-1 , leaf);
        solve(arr , i , r , leaf);
    }
    vector<int> leafNodes(int arr[],int N) {
        // code here
        vector<int>leaf;
        solve(arr , 0 , N-1 , leaf);
        return leaf;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends