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
    // using two stack
    // logic is : preorder(root,left,right) if we swap left and right it will become
    // (root,right,left) and then after reversing. it will become (left,right,root)
    // which is our need.
    // to traverse preorder, first we store root then right then left. but today we will
    // first store left then right
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        stack<TreeNode*>st1,st2;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node=st1.top();
            st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }
        while(!st2.empty()){
            TreeNode* node=st2.top();
            st2.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};