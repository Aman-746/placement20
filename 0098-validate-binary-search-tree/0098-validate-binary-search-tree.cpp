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
    // every node value should be in the range [mini,maxi]
    // left value should be in the range [mini,root->val]
    // right value should be in the range [root->val,maxi]
    bool check(TreeNode* root, long mini, long maxi){
        if(!root) return true;
        if(root->val<=mini || root->val>=maxi) return false;
        return check(root->left,mini,root->val) && check(root->right,root->val,maxi);
        
    }
    bool isValidBST(TreeNode* root) {
        return check(root,LONG_MIN,LONG_MAX);
    }
};