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
//     int solve(TreeNode* root, int ht){
        
//     }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int ans=INT_MIN;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int ht=it.second;
            ans=max(ans,ht);
            if(node->left) q.push({node->left,ht+1});
            if(node->right) q.push({node->right,ht+1});
        }
        return ans;
    }
};