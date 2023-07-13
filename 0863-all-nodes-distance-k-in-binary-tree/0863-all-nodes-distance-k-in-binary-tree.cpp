/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    // make a map to take account of node and parent for each node
    // then go to target node and traverse left,right,up and also keep track of distance
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // map will contain {node->val,parent address} for each node
        unordered_map<int,TreeNode*>mp;
        mp[root->val]=NULL;
        queue<TreeNode*>q;
        q.push(root);
        
        // creating map {node,parent}
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                mp[node->left->val]=node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right->val]=node;
            }
        }
        
        // distWise will contain left node, right node and parent node address according 
        // to distance
        queue<TreeNode*>distWise;
        distWise.push(target);
        
        // this is for the visited node, it will contain node->val and integer
        unordered_map<int,int>vis;
        vis[target->val]=1;
        int cnt=0;
        while(!distWise.empty()){
            if(cnt==k) break;
            
            int n=distWise.size();
            for(int i=0;i<n;i++){
                TreeNode* node=distWise.front();
                distWise.pop();
                if(node->left && vis.find(node->left->val)==vis.end()){
                    distWise.push(node->left);
                    vis[node->left->val]=1;
                }
                if(node->right && vis.find(node->right->val)==vis.end()){
                    distWise.push(node->right);
                    vis[node->right->val]=1;
                }
                if(mp[node->val]!=NULL && vis.find(mp[node->val]->val)==vis.end()){
                    distWise.push(mp[node->val]);
                    vis[mp[node->val]->val]=1;
                }
            }
            cnt++;
        }
        
        vector<int>ans;
        while(!distWise.empty()){
            TreeNode* node=distWise.front();
            distWise.pop();
            ans.push_back(node->val);
        }
        
        return ans;
    }
};