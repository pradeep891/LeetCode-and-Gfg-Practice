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
    
    int find_sum(TreeNode* node , int &count_node){
        if(node == nullptr) return 0;
        
        int sum = node->val;
        count_node++;
        
        sum += find_sum(node->left , count_node) + find_sum(node->right , count_node);
        return sum;       
        
    }
    void solve(TreeNode* node , int &ct){
        if(node == nullptr) return;
        
        int count_node = 0;
        int avg = find_sum(node , count_node) / count_node;
        if(avg == node->val) ct++;
        
        solve(node->left , ct);
        solve(node->right , ct);
    }
    int averageOfSubtree(TreeNode* root) {
        int ct = 0;
        solve(root , ct);
        return ct;
    }
};