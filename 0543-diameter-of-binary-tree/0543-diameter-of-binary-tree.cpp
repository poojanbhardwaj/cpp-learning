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
    int f(TreeNode*root,int &res){
        if(root == nullptr) return 0;
        int l = f(root->left,res);
        int r = f(root->right,res);
        int t = 1+ max(l,r);
        
        res = max(res,l+r);
        return t;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        f(root,res);
        return res;
    }
};