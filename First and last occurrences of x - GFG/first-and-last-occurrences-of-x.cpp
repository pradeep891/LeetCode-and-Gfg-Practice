//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int first(int ar[], int n, int num){
        int l = 0 , r = n-1 , ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(ar[mid] < num){
                l = mid + 1;
            }
            else{
                ans = mid;
                r = mid - 1;
                
            }
            
        }
        if(ar[ans] == num)
        return ans;
        return -1;
    }
    
    int last(int ar[], int n, int num){
        int l = 0 , r = n-1;
        int ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(ar[mid] <= num){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        if(ar[ans] == num)
        return ans;
        return -1;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int a = first(arr , n , x);
        int b = last(arr , n , x);
        return {a , b};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends