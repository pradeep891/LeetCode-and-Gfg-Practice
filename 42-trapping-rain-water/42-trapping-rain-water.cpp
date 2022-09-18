class Solution {
public:
    int trap(vector<int>& height) {
        int l =0 , r= height.size()-1;
        int lm = INT_MIN;
        int rm = INT_MIN;
        int ans = 0;
        
        while(l < r){
            if(height[l] <= height[r])
            {
                if(lm <= height[l])
                    lm = height[l];
                else 
                    ans += lm - height[l];
                
                l++;
            }
            else{
                if(rm <= height[r])
                    rm = height[r];
                else
                    ans += rm - height[r];
                
                r--;
            }            
            
        }
        
        return ans;
        
    }
};