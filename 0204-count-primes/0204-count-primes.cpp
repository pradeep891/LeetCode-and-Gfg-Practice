class Solution {
public:
    int countPrimes(int n) {
        vector<int>prime(n+1 , 1);
        // cout << n << " -> "; 

        for(int i=2; i*i<=n ;i++){
            if(prime[i]){
                for(int j=i*i; j<=n ;j+=i)
                    prime[j] = 0;
            }
        }
        
//         for(int i=0; i<prime.size()  ; i++){
//             if(prime[i] == 1) cout << i << " ";
//         }
        int ct = 0;
        for(int i=2; i<n; i++)
            if(prime[i] == 1) ct++;
        
        return ct;        
    }
};