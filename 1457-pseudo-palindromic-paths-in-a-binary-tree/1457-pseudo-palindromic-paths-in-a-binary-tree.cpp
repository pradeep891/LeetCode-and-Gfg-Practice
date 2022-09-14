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
    map<int , int>mp;
    
    bool check(){
        int k = 0;
        int k2 = 0;
        for(auto i : mp){
            k2 = i.second;
            if(i.second % 2 == 1)
                k++;
        }
        
        if(mp.size() == 1 && k2 == 1)
            return false;
        
        if(k <= 1)
        {
            return true;
        }
        return false;
    }
    
    void solve(TreeNode* root){
        
        
        if(root == nullptr)
            return;
       
        
        int k = root->val;
        mp[k]++;
        
//         if(check()){
//             cout << k << " -> ";
//             for(auto i : mp)
//                 cout << "{" << i.first << "," << i.second << "} ";
//             cout << endl;
            
//             ct++;
//         }
        
        
         
        if(root->left == nullptr && root->right == nullptr && check()){
            ct++;
        }
        
        solve(root->left);
        solve(root->right);
        
        if(mp[k] == 1){
            mp.erase(k);
        }
        else
            mp[k]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return 1;
        solve(root);
        // cout << endl;
        return ct;
    }
};