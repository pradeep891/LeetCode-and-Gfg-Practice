class Solution {
public:
    
    int noOfBit(int n){
        int ct = 0;
        while(n){
            ct++;
            n /= 2;
        }
        return ct ;
    }
    
    int power(long long a , int n , long long mod){
        long long res = 1;
        while(n){
            if(n % 2 == 0){
                a = (a * a) % mod;
                n /= 2;
            }
            else{
                res = (res * a) % mod;
                n--;
            }
        }
        return res;
    }
    int concatenatedBinary(int n) {
        long long ans = 1;
        long long mod = 1e9+7;
        for(int i=2; i<=n ;i++){
            int bit = noOfBit(i);
            // cout << bit << ", ";
            ans = ans * power(2 , bit , mod);
            ans = (ans + i) % mod;
            // cout << ans << " | ";
        }
        // cout << endl;
        return ans % mod;
    }
};