//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		// Your code goes here.
 		int r1= 0 ,r2 = n-1, c1 = 0, c2= m-1;
//  		while(r1 < r2 && c1 < c2){
//  		    int element = (r2 - r1) * 2  + 2 * (c2 - c1);
//  		 //   cout << element << " \n";
//  		    if(k > element)
//  		    {
//  		        k -= element;
//  		     //   cout << "remaing k = " << k << " \n";
//  		        r1++;
//  		        r2--;
//  		        c1++;
//  		        c2--;
//  		    }
//  		    else{
//  		        break;
//  		    }
//  		}
 		
// //  		cout << r1 << " " << r2 << " " << c1 << " " << c2 << " " <<  k << " \n";
//  		for(int c = c1; c <= c2; c++){
//  		    int el = a[r1][c];
//  		    k--;
 		    
//  		    if(k == 0) return el;
//  		}
//  		r1++;
 		
//  		for(int r = r1; r<=r2 ; r++){
//  		    int el = a[r][c2];
//  		    k--;
//  		    if(k == 0) return el;
//  		}
//  		c2--;
 		
//  		if(r1 <= r2){
//  		    for(int c = c2; c>=c1; c--){
//  		        int el = a[r2][c];
//  		        k--;
 		    
//  		    if(k == 0) return el;
//  		    }
//  		    r2--;
//  		}
 		
//  		if(c1 <= c2){
//  		    for(int r = r2; r>= r1; r--){
//  		         int el = a[r][c1];
//  		    k--;
//  		    if(k == 0) return el;
//  		    }
//  		    c1++;
//  		}
 		
 		
 		while(true){
 		    	for(int c = c1; c <= c2; c++){
 		    int el = a[r1][c];
 		    k--;
 		    
 		    if(k == 0) return el;
 		}
 		r1++;
 		
 		for(int r = r1; r<=r2 ; r++){
 		    int el = a[r][c2];
 		    k--;
 		    if(k == 0) return el;
 		}
 		c2--;
 		
 		if(r1 <= r2){
 		    for(int c = c2; c>=c1; c--){
 		        int el = a[r2][c];
 		        k--;
 		    
 		    if(k == 0) return el;
 		    }
 		    r2--;
 		}
 		
 		if(c1 <= c2){
 		    for(int r = r2; r>= r1; r--){
 		         int el = a[r][c1];
 		    k--;
 		    if(k == 0) return el;
 		    }
 		    c1++;
 		}
 		
 		}
 		return 0;
 		
 		
 		
//  		8 11 78
// -8 0 8 5 -4 -6 -9 1 -8 3 0
// 3 |-9 9 9 -3 -1 2 -3 9 8 |0
// -4 1 | -3 -9 -9 0 -4 -5 -5| 9 8
// 4 0 4 5 -1 -9 8 -8 -2 9 -8
// 0 -3 4 0 -5 1 -7 -5 5 9 8
// -3 0 |9 -8 -4 -5 6 6 7 |-4 6
// -2| -4 -5 3 1 -2 -1 8 2 -7 |-2
// 0 9 6 3 2 5 8 -2 -4 -8 4
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends