/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        queue<Node* >q;
        
        if(root)
            q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            vector<int>v;
            for(int i=0; i<sz; i++){
                Node* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                for(auto child : cur->children){
                    q.push(child);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};