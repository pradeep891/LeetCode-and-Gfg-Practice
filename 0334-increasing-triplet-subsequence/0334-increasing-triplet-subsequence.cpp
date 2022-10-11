class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> right = nums;
        
        int left = nums[0];
        
        for(int i=n-2 ; i>=0; i--)
            right[i] = max(right[i] , right[i+1]);
        
        for(int i=1; i<n-1; i++)
        {
            if(left < nums[i] && nums[i] < right[i+1] ) return true;
            left = min(left , nums[i]);
        }
        
        return false;
    }
};