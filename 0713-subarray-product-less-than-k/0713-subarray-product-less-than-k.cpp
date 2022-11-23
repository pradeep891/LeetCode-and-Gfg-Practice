class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0;
        int right= 0;
        int ans = 0;
        long long int product = 1;
        while(right < nums.size()){
            if(nums[right] * 1LL * product < k){
                product *= nums[right];
                right++;                
            }
            else if(left == right){
                right++;
                left++;
            }
            else{
                ans += right - left;
                product /= nums[left];
                left++;
            }
        }
        while(left < nums.size()){
            ans += right-left;
            left++;
        }
        return ans;
    }
};