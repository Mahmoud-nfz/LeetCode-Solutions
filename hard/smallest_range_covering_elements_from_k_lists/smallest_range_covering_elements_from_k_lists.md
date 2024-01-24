# Problem : Smallest Range Covering Elements from K Lists

### Difficulty : **Hard**

https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

---

### Tags : **arrays, two pointers**

### Relevant Tutorials :



---

# Statement

<p>You have <code>k</code> lists of sorted integers in <strong>non-decreasing&nbsp;order</strong>. Find the <b>smallest</b> range that includes at least one number from each of the <code>k</code> lists.</p>

<p>We define the range <code>[a, b]</code> is smaller than range <code>[c, d]</code> if <code>b - a &lt; d - c</code> <strong>or</strong> <code>a &lt; c</code> if <code>b - a == d - c</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
<strong>Output:</strong> [20,24]
<strong>Explanation: </strong>
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [[1,2,3],[1,2,3],[1,2,3]]
<strong>Output:</strong> [1,1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums.length == k</code></li>
	<li><code>1 &lt;= k &lt;= 3500</code></li>
	<li><code>1 &lt;= nums[i].length &lt;= 50</code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i][j] &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code>&nbsp;is sorted in <strong>non-decreasing</strong> order.</li>
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
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        // Pair of value, list index, and index within the list
        // This will keep track of the biggest element of each array that is present in our chosen set
        // pair<element,pair<array number, index in array> 
        set<pair<int, pair<int, int>>> curr;

        // Initialize the set with the first element from each list
        for (int i = 0; i < n; i++) {
            curr.insert(make_pair(nums[i][0], make_pair(i, 0)));
        }

        int shortest = 1e9;
        int l = 1e6, r = -1e6;

        // Continue updating the range until the end of any list is reached
        while (true) {
            int x = curr.begin()->first, y = curr.rbegin()->first;

            // Update the range if the current range is smaller
            if (y - x < shortest) {
                shortest = y - x;
                r = y;
                l = x;
            }

            int i = curr.begin()->second.first, j = curr.begin()->second.second;
            j++;

            // Move to the next element in the list with the smallest value
            if (j < nums[i].size()) {
                curr.erase(curr.begin());
                curr.insert(make_pair(nums[i][j], make_pair(i, j)));
            } else {
                // Break the loop if the end of any list is reached
                break;
            }
        }

        // Check the range one more time before returning
        int x = curr.begin()->first, y = curr.rbegin()->first;
        if (y - x < shortest) {
            shortest = y - x;
            r = y;
            l = x;
        }

        // Return the smallest range as a vector
        vector<int> ans;
        ans.push_back(l);
        ans.push_back(r);
        return ans;
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
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        set<pair<int, pair<int, int>>> curr;
        for (int i = 0; i < n; i++) {
            curr.insert(make_pair(nums[i][0], make_pair(i, 0)));
        }
        int shortest = 1e9;
        int l = 1e6, r = -1e6;
        while (true) {
            int x = curr.begin()->first, y = curr.rbegin()->first;
            if (y - x < shortest) {
                shortest = y - x;
                r = y;
                l = x;
            }
            int i = curr.begin()->second.first, j = curr.begin()->second.second;
            j++;
            if (j < nums[i].size()) {
                curr.erase(curr.begin());
                curr.insert(make_pair(nums[i][j], make_pair(i, j)));
            } else {
                break;
            }
        }
        int x = curr.begin()->first, y = curr.rbegin()->first;
        if (y - x < shortest) {
            shortest = y - x;
            r = y;
            l = x;
        }
        vector<int> ans;
        ans.push_back(l);
        ans.push_back(r);
        return ans;
    }
};
```
</details>
</li>
</ul>
