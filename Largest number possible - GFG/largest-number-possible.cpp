//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        
        if(S == 0 && N > 1) return "-1";
        
        string ans = "";
        int sum = 0;
        for(int i=0; i<N; i++){
            if(S > 9){
                ans.push_back('9');
                S -= 9;
            }
            else{
                char ch = '0' + S;
                ans.push_back(ch);
                S = 0;
            }
        }
        
        
        return S == 0 ? ans : "-1";
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends