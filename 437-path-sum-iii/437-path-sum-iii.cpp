/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
     void solve(TreeNode* root , int &ans , map<long long int,int>mp,  int tar , long long int cur_sum){
        if(root == nullptr) return;
        
         cur_sum += root->val;
         
        
         if(tar == cur_sum) ans++;
         if(mp.find(cur_sum - tar) != mp.end())
             ans += mp[cur_sum - tar];
         
         mp[cur_sum]++;
         
        solve(root->left , ans , mp, tar, cur_sum);
        solve(root->right , ans , mp, tar , cur_sum);      
         
         int val = mp[cur_sum];
         if(val == 1)
             mp.erase(cur_sum);
         else
             mp[cur_sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        map<long long int , int>mp;
        int ans = 0;
        int cur_sum = 0;
        // mp[0] = 1;
        solve(root , ans , mp , targetSum , cur_sum);
        return ans;  
    }
};