//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        // code here
        vector<string>nums;
        for(int i=0; i<10; i++){
            nums.push_back(to_string(i));
        }
        
        int start = 0 , end = 9;
        for(int digit = 2; digit<=9; digit++){
            for(int i=start ; i<=end; i++){
                string k = nums[i];
                if(k == "0")
                continue;
                
                int last = k.back() - '0';
                if(last -1 >= 0)
                nums.push_back(k + to_string(last - 1));
                if(last + 1 <10)
                nums.push_back(k + to_string(last + 1));
            }
            
            start = end + 1;
            end = nums.size() - 1;
        }
        long long ans;
        for(auto i : nums){
            long long k = stol(i);
            if(k <= X)
            ans = k;
            else
            break;
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends