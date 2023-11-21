//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>>activity;
        for(int i=0; i<n; i++){
            activity.push_back({start[i], end[i]});
            
        }
        
        sort(activity.begin(), activity.end(), [&](pair<int,int>&a, pair<int,int>&b){
            return a.second < b.second;
        });
        
        // for(auto i : activity) cout << i.first << " " << i.second << " | ";
        
        int x = -1;
        int ct = 0;
        for(int i=0; i<n; i++){
            if(activity[i].first > x){
                ct++;
                x = activity[i].second;
            }
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends