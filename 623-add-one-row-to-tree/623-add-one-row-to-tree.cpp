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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* cur = new TreeNode(val);
            cur->left = root;
            return cur;
        }   
        
        queue<TreeNode* >q;
        q.push(root);
        
        for(int i=2; i<depth ; i++){
            int sz = q.size();
            for(int j=0; j<sz; j++){
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        int sz = q.size();
            for(int j=0; j<sz; j++){
                TreeNode* cur = q.front();
                q.pop();
                
                TreeNode* left = cur->left;
                TreeNode* right = cur->right;
                
                TreeNode* lrow = new TreeNode(val);
                TreeNode* rrow = new TreeNode(val);
                lrow->left = left;
                rrow->right = right;
                
                cur->left = lrow;
                cur->right = rrow;
                
            }
        
        return root;
        
    }
};