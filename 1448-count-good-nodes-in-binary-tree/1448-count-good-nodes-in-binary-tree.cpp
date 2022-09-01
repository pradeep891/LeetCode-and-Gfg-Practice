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
    
    void solve(TreeNode* root , int mx , int &ct){
        if(root == nullptr)
            return;
        
        if(root->val >= mx){
            ct++;
            // cout << root->val << " ";
        }
        solve(root->left , max(mx , root->val) , ct);
        solve(root->right , max(mx , root->val) , ct);
    }
    int goodNodes(TreeNode* root) {
        int ct = 0;
        solve(root , INT_MIN , ct);
        return ct;
    }
};