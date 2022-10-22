//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int fillingBucket(int N) {
        // code here
        long long ar[N+1] = {0};
        long long mod = 1e8;
        
        ar[1] = 1;
        if(N == 1) return 1;
        
        ar[2] = 2;
        
        for(int i=3; i<=N ; i++)
        ar[i] = (ar[i-1] + ar[i-2]) % mod;
        
        return ar[N];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends