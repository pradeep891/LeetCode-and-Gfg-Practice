//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool static cmp(string a , string b){
        if(a.size() == b.size()) return a < b;
        return a.size() > b.size();
    }
    string longestString(vector<string> &words)
    {
        // code here
        sort(words.begin() , words.end() , cmp);
        map<string,int>mp;
        for(auto i : words) mp[i] = 1;
        for(auto i : words) {
            // cout << i << " ";
            bool ans = true;
            for(int j =0; j<i.size() ; j++){
                if(mp.find(i.substr(0 , j+1)) == mp.end()){
                    ans = false;
                    break;
                }
            }
            if(ans) return i;
        }
        return "";
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution obj;
        string w = obj.longestString(v);
        cout << w << "\n";
    }
    return 0;
}

// } Driver Code Ends