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
    
    int ct = 0;    
    int ar[10] = {0};    
    bool check(){
        int k = 0;
        for(int i=0; i<10; i++){
            if(ar[i] % 2 == 1)
                k++;
        }
        return k <= 1 ;
    }
    
    void solve(TreeNode* root){       
        
        if(root == nullptr)
            return;       
        
        int k = root->val;
        ar[k]++;
        if(root->left == nullptr && root->right == nullptr && check()) ct++;
        
        solve(root->left);
        solve(root->right);
        
        ar[k]--;        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root);
        return ct;
    }
};