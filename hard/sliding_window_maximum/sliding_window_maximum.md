# Problem : Sliding Window Maximum

### Difficulty : **Hard**

https://leetcode.com/problems/sliding-window-maximum/

---

### Tags : **Sliding window, arrays**

### Relevant Tutorials :



---

# Statement

<p>You are given an array of integers&nbsp;<code>nums</code>, there is a sliding window of size <code>k</code> which is moving from the very left of the array to the very right. You can only see the <code>k</code> numbers in the window. Each time the sliding window moves right by one position.</p>

<p>Return <em>the max sliding window</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,-1,-3,5,3,6,7], k = 3
<strong>Output:</strong> [3,3,5,5,6,7]
<strong>Explanation:</strong> 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       <strong>3</strong>
 1 [3  -1  -3] 5  3  6  7       <strong>3</strong>
 1  3 [-1  -3  5] 3  6  7      <strong> 5</strong>
 1  3  -1 [-3  5  3] 6  7       <strong>5</strong>
 1  3  -1  -3 [5  3  6] 7       <strong>6</strong>
 1  3  -1  -3  5 [3  6  7]      <strong>7</strong>
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1], k = 1
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= k &lt;= nums.length</code></li>
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> window;

        // Initialize the window with the first 'k' elements
        for (int i = 0; i < k; i++) {
            window.insert(nums[i]);
        }

        // Add the maximum of the initial window to the result
        ans.push_back(*window.rbegin());

        int i = 0, j = k;

        // Slide the window from left to right
        while (j < nums.size()) {
            // Remove the element that goes out of the window from the multiset
            window.erase(window.find(nums[i]));

            // Insert the new element that comes into the window
            window.insert(nums[j]);

            // Add the maximum of the current window to the result
            ans.push_back(*window.rbegin());

            i++;
            j++;
        }

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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> window;
        for (int i = 0; i < k; i++) {
            window.insert(nums[i]);
        }
        ans.push_back(*window.rbegin());
        int i = 0, j = k;
        while (j < nums.size()) {
            window.erase(window.find(nums[i]));
            window.insert(nums[j]);
            ans.push_back(*window.rbegin());
            i++;
            j++;
        }
        return ans;
    }
};
```
</details>
</li>
</ul>
