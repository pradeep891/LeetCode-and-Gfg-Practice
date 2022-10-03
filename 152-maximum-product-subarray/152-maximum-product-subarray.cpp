class Solution {
public:
    
    int solve(vector<int>nums , int low , int high , int &ans){
        // cout << "low = " << low << " ,  high << " << high << endl;
        int neg = 0;
        vector<int>pre = nums , suf = nums;
        
        for(int i=low; i<=high; i++){
            if(nums[i] < 0) neg++;
            
            if(i != low) pre[i] = pre[i-1] * nums[i];
        }
        
        for(int i=high-1; i>=low; i--){
            suf[i] = suf[i+1] * nums[i];
        }
        
        // cout << "suf = ";
        // for(auto i : suf)
        //     cout << i << " ";
        // cout << endl;
        
        if(neg % 2 == 0) return ans = max(ans , suf[low]);
        
        // cout << "neg = " << neg << endl;
    
        for(int i=low; i<=high; i++){
            if(nums[i] < 0){
                int l = INT_MIN , r = INT_MIN;
                if(i != low) l = pre[i-1];                
                if(i!= high) r = suf[i+1];
                
                ans = max({l , r , ans});
            }
            ans = max(ans , nums[i]);
        }
        return ans;        
    }
    int maxProduct(vector<int>& nums) {
        int zero = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) zero++;
        }
        
        int n = nums.size();
        int ans = INT_MIN;
        if(zero == 0){
            return solve(nums , 0, n-1 , ans);
        }
        
        ans = 0;
        
        int i=0 , l = 0;
        while(i < n){
            if(nums[i] ==  0){
                if(i-1 >= l)
                solve(nums , l , i-1 , ans);
                ans = max(ans , 0);
                l = i+1;                
            }
            i++;
        }
        
                if(i-1 >= l)
                solve(nums , l , i-1 , ans);
        
        return ans;
    }
};