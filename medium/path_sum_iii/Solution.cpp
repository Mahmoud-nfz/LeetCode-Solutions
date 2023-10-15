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

#define ll long long

class Solution {
public:
    int numPaths = 0; // Initialize a variable to keep track of the number of paths

    // Depth-first search to explore all paths in the binary tree
    void dfs(TreeNode* root, int targetSum) {
        if(root->left){
            dfs(root->left, targetSum);
        }
        if(root->right){
            dfs(root->right, targetSum);
        }
        searchPathsNode(root, targetSum); // Search for paths starting from this node
    }

    // Search for paths starting from the given node
    void searchPathsNode(TreeNode* root, ll targetSum) {
        if(root->val == targetSum)
            numPaths++; // If the current node's value equals the targetSum, increment the path count

        if(root->left){
            searchPathsNode(root->left, targetSum - root->val); // Recursively search for paths from the left child node
        }
        if(root->right){
            searchPathsNode(root->right, targetSum - root->val); // Recursively search for paths from the right child node
        }
    }

    // Main function to initiate the path counting
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return 0; // If the root is null, return 0 as there are no paths

        dfs(root, targetSum); // Initiate the depth-first search
        return numPaths; // Return the total number of paths found
    }
};
