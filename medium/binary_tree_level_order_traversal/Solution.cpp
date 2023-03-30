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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // create two vectors to store the current and next level nodes
        vector<TreeNode*> curr , next ;
        // if the root exists, add it to the current level
        if(root)
            curr.push_back(root) ;
        // create a vector of vectors to store the result
        vector<vector<int>> res ;
        // iterate over the current level until it's empty
        while(!curr.empty()){
            // create a temporary vector to store the values of the current level nodes
            vector<int> temp ;
            // iterate over the nodes in the current level
            for(auto elem : curr){
                // if the node has a left child, add it to the next level
                if(elem->left)
                    next.push_back(elem->left) ;
                // if the node has a right child, add it to the next level
                if(elem->right)
                    next.push_back(elem->right) ;
                // add the value of the current node to the temporary vector
                temp.push_back(elem->val) ;
            }
            // update the current level to be the next level
            curr = next ;
            // clear the next level vector
            next = vector<TreeNode*>() ;
            // add the temporary vector to the result vector
            res.push_back(temp) ;
        }
        // return the result vector
        return res ;
    }
};
