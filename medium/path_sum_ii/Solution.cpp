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
    // Helper function to recursively find all paths from root to leaf nodes that sum to targetSum
    vector<vector<int>> findPathSum(TreeNode* root, int targetSum) {
        // Initialize answer and children arrays
        vector<vector<int>> ans, children[2] ;
        // If root is NULL and targetSum is 0, add empty vector to answer (edge case)
        if(!root){
            if(targetSum == 0){
                ans.push_back(vector<int>(0)) ;
            }
            return ans ;
        }
        // If left child exists, recursively find all paths from left child to leaf nodes that sum to targetSum - root->val
        if(root->left)
            children[0] = findPathSum(root->left,targetSum - root->val) ;
        // If right child exists, recursively find all paths from right child to leaf nodes that sum to targetSum - root->val
        if(root->right)
            children[1] = findPathSum(root->right,targetSum - root->val) ;
        // If root is a leaf node, recursively find all paths from root to itself that sum to targetSum - root->val
        if(!root->left && !root->right)
            children[1] = findPathSum(root->right,targetSum - root->val) ;
        // Iterate through the children array and append each path to ans vector, adding the root value to each path
        for(auto x : children){
            if(x.size()){
                for(auto v : x){
                    v.push_back(root->val) ;
                    ans.push_back(v) ;
                }
            }
        }
        // Return all paths from root to leaf nodes that sum to targetSum
        return ans ;
    }
    
    // Main function to find all paths from root to leaf nodes that sum to targetSum
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        // Edge case: If root is NULL, return empty vector
        if(!root)
            return vector<vector<int>> (0) ;
        // Find all paths from root to leaf nodes that sum to targetSum using the helper function
        vector<vector<int>> ans = findPathSum(root, targetSum) ;
        // Reverse the order of each path and return the resulting answer
        for(int i = 0 ; i < ans.size() ; i ++)
            reverse(ans[i].begin(),ans[i].end()) ;
        return ans ;
    }
};
