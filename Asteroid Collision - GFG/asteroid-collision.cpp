//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int>st;
        for(auto i : asteroids){
            if(st.empty() || i >= 0){
                st.push(i);
                continue;
            }
            
            while(st.empty() == false && st.top() >= 0 && st.top() < -1 * i){
                st.pop();
            }
            
            if(st.empty() == false && st.top() == -1 * i){
                st.pop();
            }
            else if(st.empty() == false && st.top() < 0) {
                st.push(i);
            }
            else if(st.empty())
            st.push(i);
        }
        
        vector<int>ans;
        while(st.empty() == false){
            ans.push_back(st.top());
            st.pop();
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
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends