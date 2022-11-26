//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    reverse(A.begin() , A.end());
	    reverse(B.begin() , B.end());
	    string ans = "";
	    int carry = 0;
	    
	    for(int i=0; i<max(A.size() , B.size()); i++){
	        int a = 0 , b = 0;
	        if(i<A.size()) a = A[i] - '0';
	        if(i<B.size()) b = B[i] - '0';
	        int sum = a + b + carry;
	        carry = sum / 2;
	        sum %= 2;
	        ans.push_back(sum + '0');
	    }
	    if(carry) ans.push_back('1');
	    
	    while(ans.back() == '0') ans.pop_back();
	    
	    reverse(ans.begin() , ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends