# Problem : Find Median from Data Stream

### Difficulty : **Hard**

https://leetcode.com/problems/find-median-from-data-stream/

---

### Tags : **policy based data structures, online algorithms**

### Relevant Tutorials :



---

# Statement

<p>The <strong>median</strong> is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.</p>

<ul>
	<li>For example, for <code>arr = [2,3,4]</code>, the median is <code>3</code>.</li>
	<li>For example, for <code>arr = [2,3]</code>, the median is <code>(2 + 3) / 2 = 2.5</code>.</li>
</ul>

<p>Implement the MedianFinder class:</p>

<ul>
	<li><code>MedianFinder()</code> initializes the <code>MedianFinder</code> object.</li>
	<li><code>void addNum(int num)</code> adds the integer <code>num</code> from the data stream to the data structure.</li>
	<li><code>double findMedian()</code> returns the median of all elements so far. Answers within <code>10<sup>-5</sup></code> of the actual answer will be accepted.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
<strong>Output</strong>
[null, null, null, 1.5, null, 2.0]

<strong>Explanation</strong>
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-10<sup>5</sup> &lt;= num &lt;= 10<sup>5</sup></code></li>
	<li>There will be at least one element in the data structure before calling <code>findMedian</code>.</li>
	<li>At most <code>5 * 10<sup>4</sup></code> calls will be made to <code>addNum</code> and <code>findMedian</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>If all integer numbers from the stream are in the range <code>[0, 100]</code>, how would you optimize your solution?</li>
	<li>If <code>99%</code> of all integer numbers from the stream are in the range <code>[0, 100]</code>, how would you optimize your solution?</li>
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
#include <bits/extc++.h> // pbds
using namespace __gnu_pbds;
typedef tree< 
                pair<int,int>,          // Pair of integers (value, index)
                null_type,              // No mapped value
                less<pair<int,int>>,   // Comparator: sort based on the first integer
                rb_tree_tag,            // Red-black tree
                tree_order_statistics_node_update  // Supports order statistics
            > ordered_set_pair; 
                        
class MedianFinder {
public:
    ordered_set_pair tree; // Define a tree of pairs to store values and indices
    int i = 0; // Index counter

    MedianFinder() {
        // Constructor not doing anything
        // int md = 0; // Unused variable
        // int check = 0; // Unused variable
    }
    
    void addNum(int num) {
        // Insert the number into the tree along with its index
        // The index is incremented to maintain uniqueness
        this->tree.insert({num, i++});
    }
    
    double findMedian() {
        // Get the size of the tree
        int n = this->tree.size();

        // If the size is odd, return the middle element
        if (n % 2)
            return tree.find_by_order(n / 2)->first;
        // If the size is even, return the average of the two middle elements
        else
            return 0.5 * ((tree.find_by_order(n / 2)->first) + tree.find_by_order(n / 2 - 1)->first);
    }
};

```
</details>
</li>

<li>
<details>
    <summary>Raw Solution</summary>

```cpp
#include <bits/extc++.h> 
using namespace __gnu_pbds;
typedef tree< 
                pair<int,int>,          
                null_type,              
                less<pair<int,int>>,   
                rb_tree_tag,            
                tree_order_statistics_node_update  
            > ordered_set_pair; 
class MedianFinder {
public:
    ordered_set_pair tree; 
    int i = 0; 
    MedianFinder() {
    }
    void addNum(int num) {
        this->tree.insert({num, i++});
    }
    double findMedian() {
        int n = this->tree.size();
        if (n % 2)
            return tree.find_by_order(n / 2)->first;
        else
            return 0.5 * ((tree.find_by_order(n / 2)->first) + tree.find_by_order(n / 2 - 1)->first);
    }
};
```
</details>
</li>
</ul>
