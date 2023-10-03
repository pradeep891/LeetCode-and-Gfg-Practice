//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
  
    int findindex(char ch , string s){
        for(int i=0; i<s.size(); i++){
            if(s[i] == ch) return i;
        }
        return -1;
    }
    int romanToDecimal(string &str) {
        // code here
        vector<int>value = {1, 5, 10, 50, 100, 500, 1000};
        string roman = "IVXLCDM";
        
        int n = str.size();
        int ans = 0;
        for(int i=0; i<n ;i++){
            int index = findindex(str[i] , roman);
            ans += value[index];
            if(i == 0) continue;
            int indexprev = findindex(str[i-1] , roman);
            if(indexprev < index){
                ans -= 2 * value[indexprev];
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
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends