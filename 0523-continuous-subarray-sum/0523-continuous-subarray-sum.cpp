class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // cout << endl;
        map<int , int> mp;
        int sum = 0;
        for(int i=0; i<nums.size() ;i++){
            // cout << i << " ";
            sum += nums[i];
            int rem = sum % k;
            if(rem == 0 && i != 0) return true; 
            if(mp.find(rem) == mp.end()){                
                mp[rem] = i;
                continue;
            }
            
                int pre = mp[rem];
                if(pre+1!=i) return true;   
        }
        return false;
    }
};