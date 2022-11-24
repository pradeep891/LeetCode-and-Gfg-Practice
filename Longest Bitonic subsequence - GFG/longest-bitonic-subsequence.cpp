//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int>pre(n) , suf(n);
	    
	    pre[0] = 1 , suf[n-1] = 1;
	    for(int i=1; i<n; i++){
	        int temp = 0;
	        for(int j=i-1; j>=0; j--){
	            if(nums[j] < nums[i]){
	                temp = max(temp , pre[j]);
	            }
	        }
	        pre[i] = temp+1;
	    }
	    
	    for(int i=n-2; i>=0 ; i--){
	        int temp = 0;
	        for(int j=i+1; j<n; j++){
	            if(nums[j] < nums[i]){
	                temp = max(temp , suf[j]);
	            }
	        }
	        suf[i] = temp+1;
	    }
	    
	    int ans = 0;
	   // cout << "pre = " ;
	   // for(auto i : pre) cout << i << " " ;
	   // cout << endl;
	   // cout << "suf = " ;
	   // for(auto i : suf) cout << i << " " ;
	   // cout << endl;
	    
	    for(int i=0; i<n; i++){
	       // if(pre[i] > 1 && suf[i] > 1)
	        ans = max(ans , pre[i] + suf[i] - 1);
	       // cout <<  ans << " | ";
	    }
	    return ans;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends