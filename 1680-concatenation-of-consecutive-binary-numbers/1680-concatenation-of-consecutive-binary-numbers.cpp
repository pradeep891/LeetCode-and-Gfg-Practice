class Solution {
public:
    
    int concatenatedBinary(int n) {
        long long ans = 1;
        long long mod = 1e9+7;
        for(int i=2; i<=n ;i++){
            int j = i;
            while(j){
                ans = (ans << 1) % mod;
                j /= 2;
            }
            ans = (ans + i ) % mod;
        }
        return ans % mod;
    }
};