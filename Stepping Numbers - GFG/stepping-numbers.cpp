//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    int steppingNumbers(int n, int m)
    {
        // Code Hereveco
        vector<string>step;
        map<int , vector<string> >digit;
        for(int i=0; i<10; i++){
            step.push_back(to_string(i));
        }
        digit[1] = step;
        
        for(int i=2; i<=7; i++){
            step = digit[i-1];
            for(auto str : step){
                int last = str[str.size() - 1] - '0';
                if(last + 1 < 10)
                digit[i].push_back(str + to_string(last + 1));
                if(last - 1 >= 0)
                digit[i].push_back(str + to_string(last - 1));
            }
        }
        int ct = 0;
        for(auto i : digit){
            for(auto s : i.second) {
                int cur = stoi(s);
                if(to_string(cur).size() != s.size()) continue;
                if(n <= cur && cur <= m) ct++;
            }
        }
        return ct;
        
    }
};


//{ Driver Code Starts.

int main()
{
    Solution obj;
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends