class Solution {
public:
    
    int findPeakElement(vector<int>& nums) {
        int i=0 , j = nums.size() - 1;
        while( i <= j){
            int m = i + (j - i) / 2;
            // cout << i << " " << m << " " << j << endl;
            // if(m+1 > j || m-1 < i || (nums[m] > nums[m+1] && nums[m] > nums[m-1]))
            //     return m;
            
            if(m+1 <= j && m-1 >= i && nums[m] > nums[m+1] && nums[m] > nums[m-1]){
                return m ;
                cout << "p ";              
            }
            else if(m+1 <= j && nums[m] < nums[m+1]){
                i = m + 1;
            }
            else if(m-1 >= i && nums[m] < nums[m-1]){
                j = m - 1;
            }
            else 
                return m;
        }
        return 0;
    }
};