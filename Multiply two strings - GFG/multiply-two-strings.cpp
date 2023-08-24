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
       vector<vector<int>>v;
       int zero = -1;
       for(auto i : s2){
           zero++;
            if(i == '-') break;
           vector<int>temp(zero , 0);
           int carry = 0;
           for(auto j : s1){
               if(j == '-') break;
               int p = j - '0';
               int q = i - '0';
               
               int res = p * q + carry;
               temp.push_back(res % 10);
               carry = res / 10;
           }
           temp.push_back(carry);
           while(temp.size() < len) temp.push_back(0);
           v.push_back(temp);
           
       }
       
    //   for(auto i : v){
    //       for(auto j :  i) cout << j << " ";
    //       cout << endl;
    //   }
       
       vector<int>res;
       int carry = 0;
       
       for(int i=0; i<v[0].size(); i++){
           for(int j=0; j<v.size(); j++){
               carry += v[j][i];
           }
           res.push_back(carry % 10);
            carry /= 10;
       }
    
    
      while(carry){
          res.push_back(carry % 10);
            carry/= 10;
      }
      
      while(res.back() == 0) res.pop_back();
       
       string ans = "";
       if(sign == -1) ans.push_back('-');
       
       reverse(res.begin(), res.end());
       for(auto i : res) {
           char ch = i + '0';
           ans.push_back(ch);
       }
       return ans;
    //   for(auto i : res) cout << i << " ";
    //   cout << endl;
    //   return "";
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