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
    
    void solve(TreeNode* root , vector<vector<int>>&ans , vector<int>&cur , int tar){
        if(root == nullptr) return;
        
        cur.push_back(root->val);
        if(tar  == root->val  && root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        
        solve(root->left , ans , cur , tar-root->val);
        solve(root->right , ans , cur , tar-root->val);
        
        cur.pop_back();        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>cur;
        
        solve(root , ans , cur , targetSum);
        return ans;        
    }
};