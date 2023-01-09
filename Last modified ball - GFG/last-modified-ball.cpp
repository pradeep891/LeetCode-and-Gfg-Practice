//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int N, vector<int> A) {
        // code here
        int carry = 0;
        A[N-1]++;
        int ans = N;
        for(int i=N-1; i>=0; i--){
            if(A[i] + carry > 9){
                carry = 1;
                ans = i;
            }
            else {
                carry = 0;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}
    
// } Driver Code Ends