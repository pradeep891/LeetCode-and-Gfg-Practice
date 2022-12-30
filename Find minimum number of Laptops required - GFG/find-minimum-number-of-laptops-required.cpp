//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        vector<pair<int,int>>v;
        for(int i=0; i<N; i++)
        v.push_back({start[i] , end[i]});
        
        sort(v.begin() , v.end());
        
        int maxlap = 0;
        priority_queue<int , vector<int> , greater<int> >pq;
        
        int sz = 0;
        for(auto i : v){
            if(pq.empty()){
                pq.push(i.second);
                sz++;
                maxlap = max(maxlap , sz);
                continue;
            }
            
            int top = pq.top();
            if(top <= i.first){
                pq.pop();
                sz--;
            } 
            
            pq.push(i.second);
            sz++;
            maxlap = max(maxlap , sz);
        }
        return maxlap;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends