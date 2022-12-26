//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
   
    long long C(long long n , int r){
        if(n < r) return 0;
        long long ans = 1;
        for(int i = n-r+1 ; i<= n; i++) ans*= i;
        
        int k = 1;
        for(int i=2; i<=r; i++) k*= i;
        
        ans = ans / k;
        // cout << "n-> " << n << "  r-> " << r <<  "  T-> " << ans << " \n";
        return ans;
    }
    
    void precompute(){
        
    }
    long long help(long long x){
        vector<int>v;
        // cout << "X = " << x << " , v = ";
        while(x){
            v.push_back(x % 2);
            x /= 2;
        }
        int len = v.size();
        reverse(v.begin() , v.end());
        
        // for(auto i : v) cout << i << " " ;
        // cout << endl;
        long long ans = 0;
        int ct1 = 0;
        for(int i=0; i<v.size() ; i++){
            
            if(v[i] == 0) continue;
            else if(v[i] == 1) ct1++;
            if(ct1 == 4) {
                ans++;
                break;
            }
            
            int rem = len - i - 1;
            ans += C(rem , 3 - ct1 + 1);
        }
        return ans;
    }
    
    long long solve(long long l, long long r){
        // Code Here
        long long a = help(r+1);
        long long b = help(l);
        // cout << "a = " << a << " , b = " << b << endl;
        return a - b;
    }
    
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends