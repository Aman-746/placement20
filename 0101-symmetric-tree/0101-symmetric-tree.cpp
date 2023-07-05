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
    bool isSymmetricTree(TreeNode* left, TreeNode* right){
        // if left and right both is not equal means both should be null if not then it will
        // return false;
        if(!left || !right) return left==right;
        if(left->val!=right->val) return false;
        return isSymmetricTree(left->left,right->right) && isSymmetricTree(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetricTree(root->left,root->right);
    }
};