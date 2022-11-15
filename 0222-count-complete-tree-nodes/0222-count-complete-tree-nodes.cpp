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
    int ans = 0;
    int countNodes(TreeNode* root , int n = 1) {
        if(root == nullptr) return 0;     
        countNodes(root->right , 2*n + 1);
        countNodes(root->left , 2*n);
        ans = max(ans , n);
        return ans;
    }
};