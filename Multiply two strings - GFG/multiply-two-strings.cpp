//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       int sign = 1;
       
       
       if(s1[0] == '-' && s2[0] == '-') ;
       else if(s1[0] == '-' || s2[0] == '-') sign = -1;
       
       reverse(s1.begin(), s1.end());
       reverse(s2.begin(), s2.end());
       
       int len = s1.size() + s2.size() + 1;
       vector<int>prev(len , 0);
       
       int zero = -1;
       for(auto i : s2){
           zero++;
            if(i == '-') break;
            
           int carry = 0;
           int id = zero;
           for(auto j : s1){
               
               if(j == '-') break;
               int p = j - '0';
               int q = i - '0';
              
               int res = p * q + carry + prev[id];
               prev[id] = res % 10;
               carry = res / 10;
                id++;
           }
           while(carry){
             int res =  carry + prev[id];
               prev[id] = res % 10;
               carry = res / 10;
               id++;
           }
           
           
       }
 
      while(prev.back() == 0) prev.pop_back();
       
      string ans = "";
      if(sign == -1) ans.push_back('-');
       
       for(int i=prev.size()-1; i>=0; i--){
           char ch = prev[i] + '0';
          ans.push_back(ch);
       }
       
      return ans;
      
    }

};

//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends