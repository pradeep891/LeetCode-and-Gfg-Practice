class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        
        int closest = 1e6;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            int j=i+1 , k=n-1;
            // cout << i << "  , ";
            while(j < k){
            // cout << "j , k = " << j << " " << k << " -> ";
                int sum = nums[j] + nums[k];
                int total = sum + nums[i];
                if(abs(target - closest) > abs(total - target)){
                    closest = total;
                    // cout << closest << " || ";     
                }
                
                if(total == target)
                    return target;
                else if(total < target)
                    j++;
                else 
                    k--;
            }
            // cout << endl;
        }
        return closest;
    }
};