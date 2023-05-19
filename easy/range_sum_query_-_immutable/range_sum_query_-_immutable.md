# Problem : Range Sum Query - Immutable

### Difficulty : **Easy**

https://leetcode.com/problems/range-sum-query-immutable/

---

### Tags : **dp**

### Relevant Tutorials :



---

# Statement

<p>Given an integer array <code>nums</code>, handle multiple queries of the following type:</p>

<ol>
	<li>Calculate the <strong>sum</strong> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <strong>inclusive</strong> where <code>left &lt;= right</code>.</li>
</ol>

<p>Implement the <code>NumArray</code> class:</p>

<ul>
	<li><code>NumArray(int[] nums)</code> Initializes the object with the integer array <code>nums</code>.</li>
	<li><code>int sumRange(int left, int right)</code> Returns the <strong>sum</strong> of the elements of <code>nums</code> between indices <code>left</code> and <code>right</code> <strong>inclusive</strong> (i.e. <code>nums[left] + nums[left + 1] + ... + nums[right]</code>).</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input</strong>
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
<strong>Output</strong>
[null, 1, -1, -3]

<strong>Explanation</strong>
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>5</sup> &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= left &lt;= right &lt; nums.length</code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>sumRange</code>.</li>
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
class NumArray {
public:
    // Dynamic programming array to store cumulative sums
    vector<int> dp;
    
    NumArray(vector<int>& nums) {
        // Resize dp array with size nums.size() + 1 and initialize all elements to 0
        dp.resize(nums.size() + 1, 0);
        for (int i = 1; i < nums.size() + 1; i++) {
            // Calculate cumulative sums and store in dp array
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        // Calculate the sum of elements between indices left and right using the precalculated cumulative sums
        return dp[right + 1] - dp[left];
    }
};

```
</details>
</li>

<li>
<details>
    <summary>Raw Solution</summary>

```cpp
class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        dp.resize(nums.size() + 1, 0);
        for (int i = 1; i < nums.size() + 1; i++) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    int sumRange(int left, int right) {
        return dp[right + 1] - dp[left];
    }
};
```
</details>
</li>
</ul>
