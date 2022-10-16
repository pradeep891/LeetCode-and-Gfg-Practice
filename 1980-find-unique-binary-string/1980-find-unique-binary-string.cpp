class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int len = nums[0].size();
        int total = pow(2 , len);
        
        map<int , int>arr;
        for(auto str : nums){
            int k = 0;
            int n = 0;
            for(int i=str.size()-1 ; i>=0 ; i--){
                n +=  (str[i] - '0') * pow(2 , k);
                k++;
            }
            // k++;
            arr[n] = 1;
            // cout << n << " ";
        }
        // cout << endl;
        string ans;
        for(int i=0; i<total ; i++){
            if(arr[i] == 0)
            {
                ans = convert(i , len);
                break;
            }
        }
        return ans;
    }
    
    string convert(int n , int len){
        string k = "";
        while(n){
            int p = n%2;
            n /= 2;
            k.push_back(p + '0');
        }
        
        while(k.size() < len)
            k.push_back('0');
        
        reverse(k.begin() , k.end());
        return k;
    }
};