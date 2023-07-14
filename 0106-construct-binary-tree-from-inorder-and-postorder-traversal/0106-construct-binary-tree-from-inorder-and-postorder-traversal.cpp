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
    // inorder- left root right
    // postorder- left right root
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inStart,
            int inEnd, int postStart, int postEnd, unordered_map<int,int>& in){
        
        if(inStart>inEnd || postStart>postEnd) return NULL;
        TreeNode* root=new TreeNode(postorder[postEnd]);
        int rootInd=in[root->val];
        int numsLeft=rootInd-inStart;
        
        root->left=build(inorder,postorder,inStart,rootInd-1,postStart,postStart+
            numsLeft-1,in);
        
        root->right=build(inorder,postorder,rootInd+1,inEnd,postStart+numsLeft
            ,postEnd-1,in);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        // in map is there to store element with index wise
        unordered_map<int,int>in;
        for(int i=0;i<n;i++) in[inorder[i]]=i;
        int inStart=0, inEnd=n-1;
        int postStart=0, postEnd=n-1;
        TreeNode* root=build(inorder,postorder,inStart,inEnd,postStart,postEnd,in);
        return root;
    }
};