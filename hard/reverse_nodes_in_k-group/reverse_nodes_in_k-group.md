# Problem : Reverse Nodes in k-Group

### Difficulty : **Hard**

https://leetcode.com/problems/reverse-nodes-in-k-group/

---

### Tags : **Linked List**

### Relevant Tutorials :



---

# Statement

<p>Given the <code>head</code> of a linked list, reverse the nodes of the list <code>k</code> at a time, and return <em>the modified list</em>.</p>

<p><code>k</code> is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of <code>k</code> then left-out nodes, in the end, should remain as it is.</p>

<p>You may not alter the values in the list's nodes, only nodes themselves may be changed.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [2,1,4,3,5]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 3
<strong>Output:</strong> [3,2,1,4,5]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>n</code>.</li>
	<li><code>1 &lt;= k &lt;= n &lt;= 5000</code></li>
	<li><code>0 &lt;= Node.val &lt;= 1000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow-up:</strong> Can you solve the problem in <code>O(1)</code> extra memory space?</p>


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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    // Helper function to reverse a group of k nodes in an array
    ListNode* reverseKfromArray(vector<ListNode*>& nodes, int k) {
        int i = 0, n = nodes.size();

        // Reverse the nodes in groups of k until there are k nodes left to reverse
        while (i < n - (n % k)) {
            reverse(nodes.begin() + i, nodes.begin() + i + k);
            i += k;
        }

        // Update the next pointers to link the reversed nodes together
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes[nodes.size() - 1]->next = NULL;

        return nodes[0]; // Return the new head of the reversed group
    }

    // Main function to reverse nodes in groups of k
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> nodes;

        // Convert the linked list into a vector of nodes
        while (head && head->next) {
            nodes.push_back(head);
            head = head->next;
        }
        nodes.push_back(head);

        // Call the helper function to reverse nodes in groups of k
        return reverseKfromArray(nodes, k);
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
    ListNode* reverseKfromArray(vector<ListNode*>& nodes, int k) {
        int i = 0, n = nodes.size();
        while (i < n - (n % k)) {
            reverse(nodes.begin() + i, nodes.begin() + i + k);
            i += k;
        }
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->next = nodes[i + 1];
        }
        nodes[nodes.size() - 1]->next = NULL;
        return nodes[0]; 
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<ListNode*> nodes;
        while (head && head->next) {
            nodes.push_back(head);
            head = head->next;
        }
        nodes.push_back(head);
        return reverseKfromArray(nodes, k);
    }
};
```
</details>
</li>
</ul>
