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
        map<int , map<int , vector<int> > > mp;
        vector<vector<int>>res;
    
    void solve(TreeNode* root , int r ,  int c){
        if(root == nullptr)
            return;
        
        mp[c][r].push_back(root->val);
        solve(root->left , r+1 , c-1);
        solve(root->right , r+1 , c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(root , 0 , 0);
        for(auto c : mp){
            vector<int>temp;
            for(auto r : c.second){
                sort(r.second.begin() , r.second.end());
                for(auto ele : r.second)
                    temp.push_back(ele);
            }
            res.push_back(temp);
        }
        return res;
    }
};