# Problem : Populating Next Right Pointers in Each Node

### Difficulty : **Medium**

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

---

### Tags : **binary tree, bfs**

### Relevant Tutorials :



---

# Statement

<p>You are given a <strong>perfect binary tree</strong> where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:</p>

<pre>struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
</pre>

<p>Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to <code>NULL</code>.</p>

<p>Initially, all next pointers are set to <code>NULL</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2019/02/14/116_sample.png" style="width: 500px; height: 171px;">
<pre><strong>Input:</strong> root = [1,2,3,4,5,6,7]
<strong>Output:</strong> [1,#,2,3,#,4,5,6,7,#]
<strong>Explanation: </strong>Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2<sup>12</sup> - 1]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong></p>

<ul>
	<li>You may only use constant extra space.</li>
	<li>The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.</li>
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
/*
    We first perform a level order traversal of the tree.
    Then we point each node to its next right sibling in the same level
    see : https://github.com/Mahmoud-nfz/LeetCode-Solutions/blob/main/medium/binary_tree_level_order_traversal/binary_tree_level_order_traversal.md
    for the description of the level order traversal
*/

class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> curr , next ;
        if(root)
            curr.push_back(root) ;
        while(!curr.empty()){
            vector<Node*> temp ;
            for(auto elem : curr){
                if(elem->left)
                    next.push_back(elem->left) ;
                if(elem->right)
                    next.push_back(elem->right) ;
                temp.push_back(elem) ;
            }
            for(int i = 0 ; i < temp.size() - 1 ; i ++){
                temp[i]->next = temp[i+1] ;
            }
            temp[temp.size() - 1]->next = NULL ;
            curr = next ;
            next = vector<Node*>() ;
        }
        return root ;
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
    Node* connect(Node* root) {
        vector<Node*> curr , next ;
        if(root)
            curr.push_back(root) ;
        while(!curr.empty()){
            vector<Node*> temp ;
            for(auto elem : curr){
                if(elem->left)
                    next.push_back(elem->left) ;
                if(elem->right)
                    next.push_back(elem->right) ;
                temp.push_back(elem) ;
            }
            for(int i = 0 ; i < temp.size() - 1 ; i ++){
                temp[i]->next = temp[i+1] ;
            }
            temp[temp.size() - 1]->next = NULL ;
            curr = next ;
            next = vector<Node*>() ;
        }
        return root ;
    }
};
```
</details>
</li>
</ul>
