//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.

long long check(int i, int j , int N , int M){
    if(i >= 0 && i < N && j >= 0 && j < M) return 1;
    return 0;
}
long long count(int i , int j , int N ,int M){
    long long ans = 1;
    ans += check(i-2, j+1 , N, M);
    ans += check(i-2, j-1 , N, M);
    ans += check(i+2, j+1 , N, M);
    ans += check(i+2, j-1 , N, M);
    ans += check(i-1, j-2 , N, M);
    ans += check(i-1, j+2 , N, M);
    ans += check(i+1, j-2 , N, M);
    ans += check(i+1, j+2 , N, M);
    return N*M - ans;
}
long long numOfWays(int N, int M)
{
    // write code here
    long long ans = 0;
    long long mod = 1e9 + 7;
    
    for(int i=0; i<N; i++){
        for(int j = 0 ; j<M; j++){
            ans += count(i , j , N , M) % mod;
        }
    }
    return ans % mod;
}