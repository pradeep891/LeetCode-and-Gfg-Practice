//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
        int ans = 0;
        for(int i=0; i<s.size(); i++){
            // map<char , int>mp;
            vector<int>fre(26 , 0);
            for(int j=i; j<s.size() ; j++){
                int ch = s[j] - 'a';
                fre[ch]++;
                int mn = INT_MAX , mx = -1;
                for(auto i : fre){
                    if(i != 0){
                        mn = min(mn , i);
                        mx = max(mx , i);
                    }
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends