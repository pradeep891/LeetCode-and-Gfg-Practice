//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestPerfectPiece(int arr[], int N) {
        // code here
        int ans = 1;
        int i=0;
        while(i < N){
            int j = i;
            int mx = arr[j] , mn = arr[j];
            j++;
            i++;
            int len = 1;
            while(j < N){
                mx = max(mx , arr[j]);
                mn = min(mn , arr[j]);
                
                if(mx - mn <= 1)
                i = j;
                
                else
                break;
                
                len++;
                j++;
            }
            
            ans = max(ans , len);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.longestPerfectPiece(arr,N) << endl;
    }
    return 0;
}
// } Driver Code Ends