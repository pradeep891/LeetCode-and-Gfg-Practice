//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    // function to construct tree from string
    Node *solve(string& s , int &id){
        id++;
        string num = "";
        while(id < s.size() && isdigit(s[id]))
        num.push_back(s[id++]);
        // cout << num << " "  << id << " | ";
        
        Node* root = new Node(stoi(num));
        
        if(s[id] == ')') {
            id++;
            return root;
        }
        root->left = solve(s , id);
        
        if(s[id] == ')') {
            id++;
            return root;
        }
        
        root->right = solve(s , id);
        if(s[id] == ')') {
            id++;
            return root;
        }
        return root;
    }
    Node *treeFromString(string s){
        string num = "";
        int id = 0;
        while(id < s.size() && isdigit(s[id]))
        num.push_back(s[id++]);
        
        Node* root = new Node(stoi(num));
        // cout << num << " "  << id << " | ";
        
        if(id==s.size() || s[id] == ')') return root;
        root->left = solve(s , id);
        if(id==s.size() || s[id] == ')') return root;
        root->right = solve(s , id);
        
        // cout << endl;
        return root;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends