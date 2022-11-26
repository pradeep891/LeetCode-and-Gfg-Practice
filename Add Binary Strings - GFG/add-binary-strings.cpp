//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    reverse(A.begin() , A.end());
	    reverse(B.begin() , B.end());
	    
	    if(A.size() < B.size())
	    swap(A , B);
	   // cout << A << " " << B << " | ";
	    int carry = 0;
	    for(int i=0; i<B.size(); i++){
	        int a = A[i] - '0';
	        int b = B[i] - '0';
	        a = a + b + carry;
	        carry = a / 2;
	        a %= 2;
	        A[i] = '0' + a;
	       // cout << A[i];
	    }
	    for(int i=B.size(); i<A.size(); i++){
	        int a = A[i] - '0';
	        a = a + carry;
	        carry = a / 2;
	        a %= 2;
	        A[i] = '0' + a;
	    }
	    
	    if(carry){
	        A.push_back(carry + '0');
	    }
	    
	    while(A.back() == '0')
	    A.pop_back();
	    
	    reverse(A.begin() , A.end());
	   // cout << endl;
	    return A;
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