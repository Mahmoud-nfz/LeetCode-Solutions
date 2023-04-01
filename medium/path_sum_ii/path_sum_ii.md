# Problem : Path Sum II

### Difficulty : **Medium**

https://leetcode.com/problems/path-sum-ii/

---

### Tags : **dfs, binary tree**

### Relevant Tutorials :



---

# Statement

<p>Given the <code>root</code> of a binary tree and an integer <code>targetSum</code>, return <em>all <strong>root-to-leaf</strong> paths where the sum of the node values in the path equals </em><code>targetSum</code><em>. Each path should be returned as a list of the node <strong>values</strong>, not node references</em>.</p>

<p>A <strong>root-to-leaf</strong> path is a path starting from the root and ending at any leaf node. A <strong>leaf</strong> is a node with no children.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg" style="width: 500px; height: 356px;">
<pre><strong>Input:</strong> root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
<strong>Output:</strong> [[5,4,11,2],[5,8,4,5]]
<strong>Explanation:</strong> There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg" style="width: 212px; height: 181px;">
<pre><strong>Input:</strong> root = [1,2,3], targetSum = 5
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> root = [1,2], targetSum = 0
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 5000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
	<li><code>-1000 &lt;= targetSum &lt;= 1000</code></li>
</ul>


---

# Solution 

Solutions Author : https://github.com/Mahmoud-nfz

## C++ Solution

<ul>
<li>

<details>
    <summary>Explained Solution</summary>

```cpp
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

```
</details>
</li>

<li>
<details>
    <summary>Raw Solution</summary>

```cpp
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
        for(auto x : children){
            if(x.size()){
                for(auto v : x){
                    v.push_back(root->val) ;
                    ans.push_back(v) ;
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
```
</details>
</li>
</ul>
