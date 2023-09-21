//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    int solve(int ar[], int n, int num , int isfirst){
        int l = 0 , r = n-1 , ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(ar[mid] == num){
                ans = mid;
                if(isfirst) r = mid - 1;
                else l = mid + 1;
            }
            else if(ar[mid] < num) l = mid + 1;
            else r = mid - 1;
        }
        return ans;
    }
    
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        int a = solve(arr , n , x , 1);
        int b = solve(arr , n , x , 0);
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