//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++
// 3 10
// 5 6 5
// 4 7 1 4 8 10 5 7 4 8
// 2

// 2 8
// 7 5
// 2 3 8 10 10 7 3 7
// 13

// 4 4
// 1 4 5 7
// 10 20 30 40
// 32
class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        int i = n-1;
        int j = 0;
        int ans = INT_MAX;
        int a , b;
        while(i >= 0 && j < m){
            int sum = arr[i] + brr[j];
            int dif = abs(sum - x);
            if( dif < ans){
                ans = dif;
                a = i;
                b = j;
            }
            if(sum < x) j++;
            else if(sum == x) break;
            else i--;
        }
        return {arr[a] , brr[b]};
    }
};


//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends