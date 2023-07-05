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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((p && !q) || (!p && q)) return false;
        queue<TreeNode*>q1,q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            TreeNode* node1=q1.front();
            TreeNode* node2=q2.front();
            if(node1->val!=node2->val) return false;
            
            q1.pop();
            q2.pop();
            
            if((!node1->left && node2->left) || (node1->left && !node2->left)) return false;
            if(node1->left!=NULL && node2->left!=NULL){
                q1.push(node1->left);
                q2.push(node2->left);
            }
            
            if((!node1->right && node2->right) || (node1->right && !node2->right)) return false;
            if(node1->right!=NULL && node2->right!=NULL){
                q1.push(node1->right);
                q2.push(node2->right);
            }
        }
        return true;
    }
};