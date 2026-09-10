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
    int fs(TreeNode*root){
        if(root == nullptr) return 0;
        return root->val + fs(root->left)+fs(root->right);
    }
    int size(TreeNode*root){
        if(root== nullptr) return 0;
        return 1+size(root->left) + size(root->right);
    }
    int avg(TreeNode*root){
        if(root == nullptr) return 0;
       return fs(root)/size(root);
    }
     
    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        int t = avg(root);
        if(t == root->val) ans++;
       ans+= averageOfSubtree(root->left);
        ans+=averageOfSubtree(root->right);
        return ans;
    }
};