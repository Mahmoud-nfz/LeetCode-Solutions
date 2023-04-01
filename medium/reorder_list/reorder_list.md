# Problem : Reorder List

### Difficulty : **Medium**

https://leetcode.com/problems/reorder-list/

---

### Tags : **linked list**

### Relevant Tutorials :



---

# Statement

<p>You are given the head of a singly linked-list. The list can be represented as:</p>

<pre>L<sub>0</sub> → L<sub>1</sub> → … → L<sub>n - 1</sub> → L<sub>n</sub>
</pre>

<p><em>Reorder the list to be on the following form:</em></p>

<pre>L<sub>0</sub> → L<sub>n</sub> → L<sub>1</sub> → L<sub>n - 1</sub> → L<sub>2</sub> → L<sub>n - 2</sub> → …
</pre>

<p>You may not modify the values in the list's nodes. Only nodes themselves may be changed.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/04/reorder1linked-list.jpg" style="width: 422px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4]
<strong>Output:</strong> [1,4,2,3]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/09/reorder2-linked-list.jpg" style="width: 542px; height: 222px;">
<pre><strong>Input:</strong> head = [1,2,3,4,5]
<strong>Output:</strong> [1,5,2,4,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is in the range <code>[1, 5 * 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 1000</code></li>
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
    void reorderList(ListNode* head) {
        // base cases, the list is empty or has only one node
        if(!head || !head->next)
            return ;
        
        // partition the list into two halves, the first half and the second half
        vector<ListNode*> seconHalf, firstHalf ;
        ListNode* it = head ;
        int i = 0 ;
        while(it){
            it = it->next ;
            i ++ ;
        }
        int j = 0 ;
        while(head){
            if(j >= (i+1)/2)
                seconHalf.push_back(head) ;
            else
                firstHalf.push_back(head) ;
            head = head->next ;
            j ++ ;
        }
        
        // reverse the second half
        reverse(seconHalf.begin(),seconHalf.end());
        
        // merge the first half and the reversed second half
        for(int j = 0 ; j < min(seconHalf.size(),firstHalf.size()) - 1 ; j ++){
            firstHalf[j]->next = seconHalf[j] ;
            seconHalf[j]->next = firstHalf[j+1] ;
        }
        
        // connect the last nodes of the first half and the reversed second half
        firstHalf[seconHalf.size()-1]->next = seconHalf[seconHalf.size()-1] ;
        
        // if the first half is longer, connect its last node to the second half's last node
        if(firstHalf.size() > seconHalf.size()){
            firstHalf[firstHalf.size()-1]->next = NULL ;
            seconHalf[seconHalf.size()-1]->next = firstHalf[firstHalf.size()-1] ;
        }
        // if the second half is longer, just end the list at its last node
        else{
            seconHalf[seconHalf.size()-1]->next = NULL ;
        }
        
        // set the reordered list as the new head
        head = firstHalf[0] ;
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
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return ;
        vector<ListNode*> seconHalf, firstHalf ;
        ListNode* it = head ;
        int i = 0 ;
        while(it){
            it = it->next ;
            i ++ ;
        }
        int j = 0 ;
        while(head){
            if(j >= (i+1)/2)
                seconHalf.push_back(head) ;
            else
                firstHalf.push_back(head) ;
            head = head->next ;
            j ++ ;
        }
        reverse(seconHalf.begin(),seconHalf.end());
        for(int j = 0 ; j < min(seconHalf.size(),firstHalf.size()) - 1 ; j ++){
            firstHalf[j]->next = seconHalf[j] ;
            seconHalf[j]->next = firstHalf[j+1] ;
        }
        firstHalf[seconHalf.size()-1]->next = seconHalf[seconHalf.size()-1] ;
        if(firstHalf.size() > seconHalf.size()){
            firstHalf[firstHalf.size()-1]->next = NULL ;
            seconHalf[seconHalf.size()-1]->next = firstHalf[firstHalf.size()-1] ;
        }
        else{
            seconHalf[seconHalf.size()-1]->next = NULL ;
        }
        head = firstHalf[0] ;
    }
};
```
</details>
</li>
</ul>
