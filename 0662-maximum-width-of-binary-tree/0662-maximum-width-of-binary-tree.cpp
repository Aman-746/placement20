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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,int>>q;
        int ans=0;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            // mini is actually the first node index of that particular level
            int mini=q.front().second;
            int first,last;
            for(int i=0;i<size;i++){
                long index=q.front().second-mini;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=index;
                if(i==size-1) last=index;
                if(node->left) q.push({node->left,2*index+1});
                if(node->right) q.push({node->right,2*index+2});
            }
            ans=max(ans,last-first+1);
        }   
        return ans;
    }
};