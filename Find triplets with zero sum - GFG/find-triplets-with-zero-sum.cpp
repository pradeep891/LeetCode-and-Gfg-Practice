//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
  
    bool solve(int ar[], int sum , int i, int j, int n){
        while(i >=0 && j < n){
            int cursum = ar[i] + ar[j];
            if(cursum == sum) return true;
            
            if(cursum < sum) j++;
            else i--;
        }
        return false;
    }
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr, arr + n);
        for(int i=1; i<n-1; i++){
            bool a = solve(arr, -arr[i], i-1, i+1, n);
            if(a) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends