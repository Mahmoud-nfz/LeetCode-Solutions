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
    map<ll, int> prevPathSums; // A map to store previously encountered path sums

    // Depth-first search to explore all paths in the binary tree
    void dfs(TreeNode* root, int targetSum, ll currPathSum) {
        currPathSum += root->val; // Update the current path sum
        numPaths += prevPathSums[currPathSum - targetSum]; // Check if the difference between the current path sum and the targetSum exists in previous path sums and increment the path count accordingly
        prevPathSums[currPathSum]++; // Add the current path sum to the map of previous path sums

        if (root->left) {
            dfs(root->left, targetSum, currPathSum); // Recursively explore paths from the left child node
        }
        if (root->right) {
            dfs(root->right, targetSum, currPathSum); // Recursively explore paths from the right child node
        }

        prevPathSums[currPathSum]--; // Decrement the count for the current path sum as we backtrack
    }

    // Main function to initiate the path counting
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0; // If the root is null, return 0 as there are no paths
        }

        prevPathSums[0] = 1; // Initialize the map with a count of 1 for a path sum of 0 (base case)

        dfs(root, targetSum, 0); // Initiate the depth-first search with the current path sum as 0
        return numPaths; // Return the total number of paths found
    }
};
