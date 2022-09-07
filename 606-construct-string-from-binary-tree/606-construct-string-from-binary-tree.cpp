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
    
    void solve(TreeNode* root , string &s){
        if(root == nullptr)
            return;
        
        s.push_back('(');        
        s += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {            
            s.push_back(')');
            return;
        }
        
        if(root->left){            
            solve(root->left , s);
            solve(root->right , s);
            s.push_back(')');
            return;
        }
        else{            
            s += "()";                
            solve(root->right , s);
            s.push_back(')');
        }
        
        
    }
    string tree2str(TreeNode* root) {
        string s = "";
        s += to_string(root->val);
        if(root->left == nullptr && root->right)
            s += "()";
        solve(root->left , s);
        solve(root->right , s);
        return s;
    }
};