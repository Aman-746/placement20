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
    unsigned int ans=1; // since we know number of nodes are >=1 so ans can't be zero
    unordered_map<int,unsigned int>m; // (level,index)
    
    void dfs(TreeNode* root, unsigned int index, int level){
        if(!root) return;
        
        // if we have already gone through that level means we have stored the leftmost index of         // that level so we can easily access our leftmost index of that level by just doing             // m[level]
        if(m.count(level)) ans=max(ans,index-m[level]+1);
        
        // else if we are 1st time going through that level then store it into map with                 // corresponding index and that index will be leftmost index for sure 
        else m[level]=index;
        
        dfs(root->left,index*2,level+1);
        dfs(root->right,index*2+1,level+1);
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,1,0); // initially we are at index 1 and level 0
        return ans;
    }
};