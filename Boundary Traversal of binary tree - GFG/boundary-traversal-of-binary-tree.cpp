//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
public:

// if root is leaf node then leaves function will add that into result, otherwise if it is not leaf node then
// add it to result in the very starting

// leftBoundary function will add left most nodes in result, if left is null then it will go to right
// leaves function will add leaf nodes in result
// rightBoundary function will add right most nodes in result, if right is null then it will go to left

    bool isLeaf(Node* root){
        if(!root->left && !root->right) return true;
        return false;
    }
    
    void leftBoundary(Node* root, vector<int>& res){
        Node* cur=root;
        if(!cur) return;
        if(isLeaf(cur)) return;
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) leftBoundary(cur->left,res);
        else leftBoundary(cur->right,res);
    }
    
    void leaves(Node* root, vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) leaves(root->left,res);
        if(root->right) leaves(root->right,res);
    }
    
    void rightBoundary(Node* root, vector<int>& res,int size){
        Node* cur=root;
        if(!cur) return;
        if(isLeaf(cur)) return;
        if(!isLeaf(cur)) res.insert(res.begin()+size,cur->data);
        if(cur->right) rightBoundary(cur->right,res,size);
        else rightBoundary(cur->left,res,size);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        leftBoundary(root->left,res);
        leaves(root,res);
        rightBoundary(root->right,res,res.size());
        return res;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends