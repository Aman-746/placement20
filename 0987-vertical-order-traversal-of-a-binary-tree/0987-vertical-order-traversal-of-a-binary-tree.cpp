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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // vertices,level,nodes
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int vertex=q.front().second.first;
            int level=q.front().second.second;
            q.pop();
            mp[vertex][level].insert(node->val);
            if(node->left) q.push({node->left,{vertex-1,level+1}});
            if(node->right) q.push({node->right,{vertex+1,level+1}});
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int>verticalNode;
            for(auto ss:it.second) verticalNode.insert(verticalNode.end(),ss.second.begin(),ss.second.end());
            ans.push_back(verticalNode);
        }
        return ans;
    }
};