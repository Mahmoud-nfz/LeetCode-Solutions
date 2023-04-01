# Problem : Binary Tree Level Order Traversal II

### Difficulty : **Medium**

https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

---

### Tags : **binary tree**

### Relevant Tutorials :



---

# Statement

<p>Given the <code>root</code> of a binary tree, return <em>the bottom-up level order traversal of its nodes' values</em>. (i.e., from left to right, level by level from leaf to root).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;">
<pre><strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[15,7],[9,20],[3]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
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
    // we solve the inverse problem first and then reverse the outcoming array
    // the inverse problem is https://leetcode.com/problems/binary-tree-level-order-traversal/
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
        // reverse the result vector and reverse it
        reverse(res.begin(), res.end()) ;
        return res ;
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<TreeNode*> curr , next ;
        if(root)
            curr.push_back(root) ;
        vector<vector<int>> res ;
        while(!curr.empty()){
            vector<int> temp ;
            for(auto elem : curr){
                if(elem->left)
                    next.push_back(elem->left) ;
                if(elem->right)
                    next.push_back(elem->right) ;
                temp.push_back(elem->val) ;
            }
            curr = next ;
            next = vector<TreeNode*>() ;
            res.push_back(temp) ;
        }
        reverse(res.begin(), res.end()) ;
        return res ;
    }
};
```
</details>
</li>
</ul>
