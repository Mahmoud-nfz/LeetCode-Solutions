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
    vector<vector<int>> findPathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans, children[2] ;
        if(!root){
            if(targetSum == 0){
                ans.push_back(vector<int>(0)) ;
            }
            return ans ;
        }
        if(root->left)
            children[0] = findPathSum(root->left,targetSum - root->val) ;
        if(root->right)
            children[1] = findPathSum(root->right,targetSum - root->val) ;
        if(!root->left && !root->right)
            children[1] = findPathSum(root->right,targetSum - root->val) ;
        for(int i = 0 ; i < 2 ; i++){
            if(children[i].size()){
                for(int j = 0 ; j < children[i].size() ; j ++){
                    children[i][j].push_back(root->val) ;
                    ans.push_back(children[i][j]) ;
                }
            }
        }
        return ans ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)
            return vector<vector<int>> (0) ;
        vector<vector<int>> ans = findPathSum(root, targetSum) ;
        for(int i = 0 ; i < ans.size() ; i ++)
            reverse(ans[i].begin(),ans[i].end()) ;
        return ans ;
    }
};