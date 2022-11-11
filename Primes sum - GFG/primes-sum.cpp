//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:

    bool twosum(vector<int>&v, int n){
        int i=0, j=v.size()-1;
        while(i <= j){
            int sum = v[i] + v[j];
            if(sum == n) return 1;
            else if(sum < n) i++;
            else j--;
        }
        return 0;
    }
    string isSumOfTwo(int N){
        // code here
        int mx = 1e5+3;
        vector<int>v(mx , 1);
        
        for(int i=2; i*i<mx ; i++){
            if(v[i] == 1){
                for(int j=i*i; j<mx; j+=i)
                v[j] = 0;
            }
        }
        vector<int>prime;
        
        for(int i=2; i<mx; i++){
            if(v[i] == 1)
            prime.push_back(i);
        }
        
        // for(auto i : prime)
        //  cout << i << " " ;
        //  cout << endl;
        if(twosum(prime , N))
        return "Yes";
        else
        return "No";
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isSumOfTwo(N) << endl;
    }
    return 0;
}

// } Driver Code Ends