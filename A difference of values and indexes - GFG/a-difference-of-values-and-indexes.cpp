//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 



// } Driver Code Ends
class Solution{
  public:
    int maxDistance(int arr[], int n) 
    { 
        // Complete the function
        int mxp = INT_MIN , mnp = INT_MAX;
        int mxn = mxp , mnn = mnp;
        for(int i=0; i<n; i++){
            mxp = max(mxp , arr[i] + i);
            mnp = min(mnp , arr[i] + i);
            mxn = max(mxn , arr[i] - i);
            mnn = min(mnn , arr[i] - i);
        }
        return max(mxp - mnp , mxn - mnn);
    } 
};

//{ Driver Code Starts.
int main() 
{ 
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i<n; i++)
	        cin>>arr[i];
	    Solution obj;
	    cout<<obj.maxDistance(arr, n)<<endl;
	}
} 

// } Driver Code Ends