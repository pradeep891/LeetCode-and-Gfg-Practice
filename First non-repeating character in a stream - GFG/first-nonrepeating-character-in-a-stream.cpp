//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans = "";
		    int id = 0;
		    unordered_map<char,int>mp;
		    for(int i=0; i<A.size(); i++){
		        char ch = A[i];
		        mp[ch]++;
		        ch = '#';
		        
		        while(id <= i){
		            if(mp[A[id]] == 1) {
		                ch = A[id];
		                break;
		            }
		            else{
		                id++;
		            }
		        }
		        ans.push_back(ch);
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends