# Problem : Reverse Linked List

### Difficulty : **Easy**

https://leetcode.com/problems/reverse-linked-list/

---

### Tags : **linked list**

### Relevant Tutorials :



---

# Statement

<p>Given the <code>head</code> of a singly linked list, reverse the list, and return <em>the reversed list</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [5,4,3,2,1]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg" style="width: 182px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2]
<strong>Output:</strong> [2,1]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> head = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is the range <code>[0, 5000]</code>.</li>
	<li><code>-5000 &lt;= Node.val &lt;= 5000</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> A linked list can be reversed either iteratively or recursively. Could you implement both?</p>


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
    ListNode* reverseList(ListNode* head) {
        // If the linked list is empty or has only one node, return it as is
        if(!head || !head->next)
            return head ;
        
        // Initialize elem pointer as head's next node, set head's next to NULL
        ListNode* elem = head->next ;
        head->next = NULL ;
        
        // Iterate over the remaining nodes and reverse their pointers
        while(elem){
            ListNode* newHead = elem->next ;
            elem->next = head ;
            head = elem ;
            elem = newHead ;
            if(!elem)
                return head ; // Return the reversed head of the linked list
        }
        
        return NULL ; // Should never get here
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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head ;
        ListNode* elem = head->next ;
        head->next = NULL ;
        while(elem){
            ListNode* newHead = elem->next ;
            elem->next = head ;
            head = elem ;
            elem = newHead ;
            if(!elem)
                return head ; 
        }
        return NULL ; 
    }
};
```
</details>
</li>
</ul>
