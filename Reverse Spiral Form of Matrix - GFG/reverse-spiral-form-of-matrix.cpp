//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        vector<int>ans;
        int toprow = 0 , bottomrow = R-1 , leftcol = 0 , rightcol = C-1;
        while(toprow <= bottomrow && leftcol <= rightcol){
            for(int c=leftcol ; c<=rightcol; c++)
            ans.push_back(a[toprow][c]);
            
            for(int r=toprow+1; r<bottomrow; r++)
            ans.push_back(a[r][rightcol]);
            
            if(bottomrow != toprow)
            for(int c=rightcol; c>=leftcol; c--)
            ans.push_back(a[bottomrow][c]);
            
            if(leftcol != rightcol)
            for(int r=bottomrow-1; r>toprow; r--)
            ans.push_back(a[r][leftcol]);
            
            toprow++;
            leftcol++;
            bottomrow--;
            rightcol--;
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends