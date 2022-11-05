//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int K) {
        // code here
        int ar[K] = {0};
        for(int i=0; i<N; i++)
        ar[arr[i] % K]++;
        
        int i=1, j=K-1;
        int ans = 0;
        while(i < j){
            ans += max(ar[i] , ar[j]);
            i++;
            j--;
        }
        if(ar[0] > 0) ans++;
        if(i == j && ar[i] > 0) ans += 1; 
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends