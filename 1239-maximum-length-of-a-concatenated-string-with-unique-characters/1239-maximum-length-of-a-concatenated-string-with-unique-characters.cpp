class Solution {
public:
    int solve(vector<string>&arr , int n){
        vector<int>fre(26 , 0);
        int id = 0;
        while(n){
            if(n % 2){
                for(auto ch : arr[id])
                    fre[ch - 'a']++;
            }
            id++;
            n /= 2;
        }
        
        int ct = 0;
        for(auto i : fre){
            if(i > 1) return 0;
            if(i == 1) ct++;
        }
        return ct;        
    }
    int maxLength(vector<string>& arr) {
        int len = arr.size();
        len = pow(2 , len);
        int mx = 0;
        for(int i=0 ; i<len; i++){
            mx = max(solve(arr , i) , mx);
        }
        return mx;
    }
};