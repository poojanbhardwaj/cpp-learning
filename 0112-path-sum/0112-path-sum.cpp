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
    bool f(TreeNode*root,int targetSum,int sum){
        if(root==NULL) return false;
        sum+=root->val;
        if(sum == targetSum && root->left == nullptr && root->right == nullptr) return true;
        bool l = f(root->left,targetSum,sum);
        bool r = f(root->right,targetSum,sum);
        return l||r;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return f(root,targetSum,sum);
    }
};