# Problem : Rotate List

### Difficulty : **Medium**

https://leetcode.com/problems/rotate-list/

---

### Tags : **Linked list**

### Relevant Tutorials :



---

# Statement

<p>Given the <code>head</code> of a linked&nbsp;list, rotate the list to the right by <code>k</code> places.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg" style="width: 450px; height: 191px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5], k = 2
<strong>Output:</strong> [4,5,1,2,3]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg" style="width: 305px; height: 350px;">
<pre><strong>Input:</strong> head = [0,1,2], k = 4
<strong>Output:</strong> [2,0,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[0, 500]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
	<li><code>0 &lt;= k &lt;= 2 * 10<sup>9</sup></code></li>
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
    int k, len; // 'k' for rotation count and 'len' for the list length
    ListNode* newHead; // Pointer to the new head of the list after rotation

    // Recursive function to traverse the list and adjust links
    int solve(ListNode* curr, ListNode* first, int currLen){
        // Base case: end of the list
        if(!curr){
            k = k % currLen; // Normalize k to prevent unnecessary rotations
            len = currLen; // Record the total length of the list
            return 0; // Return 0 to start indexation for adjusting links
        }

        // Recur for the next node
        int idx = solve(curr->next, first, currLen + 1);

        // Link the last node to the first node (making the list circular temporarily)
        if(!idx)
            curr->next = first;
        
        // Identify the new head just after the rotated tail
        if(idx == k-1)
            newHead = curr;
        
        // Disconnect the new tail from the rotated part
        if(idx == k)
            curr->next = NULL;

        // Return the incremented index
        return idx + 1;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        // Edge cases: no rotation needed or empty list
        if(!k || !head)
            return head;

        this->k = k; // Set the global rotation count

        // Start the recursive process
        solve(head, head, 0);

        // If k is a multiple of the list length or the list has only one element
        if((k % (this->len)) == 0 || this->len == 1){
            return head; // No change in head needed
        }
        // Return the new head of the list
        return newHead;
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
    int k, len; 
    ListNode* newHead; 
    int solve(ListNode* curr, ListNode* first, int currLen){
        if(!curr){
            k = k % currLen; 
            len = currLen; 
            return 0; 
        }
        int idx = solve(curr->next, first, currLen + 1);
        if(!idx)
            curr->next = first;
        if(idx == k-1)
            newHead = curr;
        if(idx == k)
            curr->next = NULL;
        return idx + 1;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k || !head)
            return head;
        this->k = k; 
        solve(head, head, 0);
        if((k % (this->len)) == 0 || this->len == 1){
            return head; 
        }
        return newHead;
    }
};
```
</details>
</li>
</ul>
