//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
		
	int start(int ar[], int n , int x){
	    int l = 0 , r = n-1;
	    int ans = -1;
	    while(l <= r){
	        
	        
	        int mid = l + (r - l)/2;
	       // cout << " l = " << l << " mid = " << mid << " r = " << r << endl;
	        
	        if(ar[mid] == x){
	            ans = mid; 
	            r = mid - 1;
	        }
	        else if(ar[mid] > x){
	            r = mid - 1;
	        }
	        else{
	            l = mid + 1;
	        }
	    }
	    
	    return ans;
	}
	
	
	int end(int ar[], int n , int x){
	    int l = 0 , r = n-1;
	    int ans = -1;
	    while(l <= r){
	        
	        int mid = l + (r - l)/2;
	        
	        
	        if(ar[mid] == x){
	            ans = mid; 
	            l = mid + 1;
	        }
	        else if(ar[mid] > x){
	            r = mid - 1;
	        }
	        else{
	            l = mid + 1;
	        }
	    }
	    
	    return ans;
	}
	
	int count(int arr[], int n, int x) {
	    // code here
	    int st = start(arr , n , x);
	    int en = end(arr, n , x);
	    
	   // cout << st <<" " << en << endl;
	    if(st == -1)
	    return 0;
	    return en - st + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends