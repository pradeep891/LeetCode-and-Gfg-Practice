//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    int countdigit(int n , int base){
        int ct = 0;
        while(n){
            ct++;
            n /= base;
        }
        return ct;
    }
    string baseEquiv(int n, int m){
        // code here
        int low = 2 , high = 32;
        while(low <= high){
            // cout << low << " " << high << " | ";
            int mid = low + (high - low)/2;
            int digit = countdigit(n , mid);
            
            if(digit == m) return "Yes";
            if(digit > m)
            low = mid + 1;
            else
            high = mid - 1;
        }
        
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends