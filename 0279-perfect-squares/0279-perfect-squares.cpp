class Solution {
public:
    
    int solve(int n  ,vector<int>&nums , int id){
        queue<pair<int , int>>q; // remaing num , id
        q.push({n , id});
        int ans = -1;
        while(q.empty() == false){
            int sz = q.size();
            ans++;
            for(int i=0; i<sz; i++){
                int num = q.front().first;
                int index = q.front().second;
                q.pop();
            // cout << num << " " << index << " | ";
                if(num == 0) return ans;
                for(int j=index; j>=0; j--){
                    int rem = num - nums[j];
                    // if(rem > nums[j]) break;
                    if(rem >= 0)
                    q.push({rem , j});
                }
            }
        }
        return ans;
    }
    int numSquares(int n) {        
        int k = sqrt(n);
        vector<int>nums(k , 0);
        for(int i=0; i<k; i++)
            nums[i] = (i+1) * (i+1);
        
        // for(auto i  : nums) cout << i << " " ;
        // cout << endl;
        return solve(n , nums , k-1);
    }
};