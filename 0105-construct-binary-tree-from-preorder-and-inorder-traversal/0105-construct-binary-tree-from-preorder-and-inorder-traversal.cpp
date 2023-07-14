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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd
                   , int inStart, int inEnd, unordered_map<int,int>& iomp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        
        TreeNode* root=new TreeNode(preorder[preStart]);
        
        int rootIndex=iomp[root->val];
        int numsLeft=rootIndex-inStart;
        
        root->left=build(preorder,inorder,preStart+1,preStart+numsLeft,inStart,
                        rootIndex-1,iomp);
        root->right=build(preorder,inorder,preStart+numsLeft+1,preEnd,rootIndex+1,
                         inEnd,iomp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int preStart=0,inStart=0;
        int preEnd=n-1,inEnd=n-1;
        
        // mapping of inorder elements with index .. iomp(inorder map)
        unordered_map<int,int>iomp;
        for(int i=0;i<n;i++) iomp[inorder[i]]=i;
        
        TreeNode* root=build(preorder,inorder,preStart,preEnd,inStart,inEnd,iomp);
        return root;
    }
};