# Problem : Merge k Sorted Lists

### Difficulty : **Hard**

https://leetcode.com/problems/merge-k-sorted-lists/

---

### Tags : **Linked List**

### Relevant Tutorials :



---

# Statement

<p>You are given an array of <code>k</code> linked-lists <code>lists</code>, each linked-list is sorted in ascending order.</p>

<p><em>Merge all the linked-lists into one sorted linked-list and return it.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> lists = [[1,4,5],[1,3,4],[2,6]]
<strong>Output:</strong> [1,1,2,3,4,4,5,6]
<strong>Explanation:</strong> The linked-lists are:
[
  1-&gt;4-&gt;5,
  1-&gt;3-&gt;4,
  2-&gt;6
]
merging them into one sorted list:
1-&gt;1-&gt;2-&gt;3-&gt;4-&gt;4-&gt;5-&gt;6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> lists = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> lists = [[]]
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>k == lists.length</code></li>
	<li><code>0 &lt;= k &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= lists[i].length &lt;= 500</code></li>
	<li><code>-10<sup>4</sup> &lt;= lists[i][j] &lt;= 10<sup>4</sup></code></li>
	<li><code>lists[i]</code> is sorted in <strong>ascending order</strong>.</li>
	<li>The sum of <code>lists[i].length</code> will not exceed <code>10<sup>4</sup></code>.</li>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Create a set to store pairs of (value, ListNode) for the heads of each linked list
        set<pair<int, ListNode*>> heads;

        // Insert the heads of non-empty linked lists into the set
        for (ListNode* head : lists) {
            if (head) {
                heads.insert({head->val, head});
            }
        }

        ListNode* ans = NULL;
        ListNode* curr;

        // Check if the set is not empty
        if (!heads.empty()) {
            auto firstPair = *heads.begin();
            ans = firstPair.second;
            curr = ans;
            heads.erase(heads.begin());

            // If there is a next node in the same linked list, insert it back into the set
            if (firstPair.second->next) {
                heads.insert({firstPair.second->next->val, firstPair.second->next});
            }
        }

        // Merge the linked lists in ascending order
        while (!heads.empty()) {
            auto nextPair = *heads.begin();
            curr->next = nextPair.second;
            curr = curr->next;
            heads.erase(heads.begin());

            // If there is a next node in the same linked list, insert it back into the set
            if (nextPair.second->next) {
                heads.insert({nextPair.second->next->val, nextPair.second->next});
            }
        }

        return ans; // Return the merged sorted linked list
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        set<pair<int, ListNode*>> heads;
        for (ListNode* head : lists) {
            if (head) {
                heads.insert({head->val, head});
            }
        }
        ListNode* ans = NULL;
        ListNode* curr;
        if (!heads.empty()) {
            auto firstPair = *heads.begin();
            ans = firstPair.second;
            curr = ans;
            heads.erase(heads.begin());
            if (firstPair.second->next) {
                heads.insert({firstPair.second->next->val, firstPair.second->next});
            }
        }
        while (!heads.empty()) {
            auto nextPair = *heads.begin();
            curr->next = nextPair.second;
            curr = curr->next;
            heads.erase(heads.begin());
            if (nextPair.second->next) {
                heads.insert({nextPair.second->next->val, nextPair.second->next});
            }
        }
        return ans; 
    }
};
```
</details>
</li>
</ul>
