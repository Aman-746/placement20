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
    // Morris traversal
    
    // 1st case: if left of current is null means current is the root there so add
    // in answer and current pointer should point in right
    
    // 2nd case: if left of current is not null then go to the right most node of
    // current left and right of right most node should point to current so that we 
    // don't need to traverse through its parent, simply go to the current node. At
    // first time only need to attach to upper node then current should point in current
    // left
    
    // one more case is here ki when i am at the right most node and that is already 
    // threaded to the upper node/ parent node (it means that we have already
    // printed left side nodes) then remove that node and current will
    // be now current right
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        TreeNode* cur=root;
        vector<int>ans;
        while(cur){
            if(cur->left==NULL){
                ans.push_back(cur->val);
                cur=cur->right;
            }
            else{
                // go to right most node of left of current node
                TreeNode* left=cur->left;
                while(left->right && left->right!=cur) left=left->right;
                if(left->right==NULL){
                    left->right=cur;
                    cur=cur->left;
                }
                else{
                    left->right=NULL;
                    ans.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return ans;
    }
};