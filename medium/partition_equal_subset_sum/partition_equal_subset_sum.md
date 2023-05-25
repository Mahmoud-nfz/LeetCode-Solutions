# Problem : Partition Equal Subset Sum

### Difficulty : **Medium**

https://leetcode.com/problems/partition-equal-subset-sum/

---

### Tags : **dp**

### Relevant Tutorials :



---

# Statement

<p>Given an integer array <code>nums</code>, return <code>true</code> <em>if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,5,11,5]
<strong>Output:</strong> true
<strong>Explanation:</strong> The array can be partitioned as [1, 5, 5] and [11].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,5]
<strong>Output:</strong> false
<strong>Explanation:</strong> The array cannot be partitioned into equal sum subsets.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 100</code></li>
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
    // Variable to store the size of the input array
    int n;
    // 2D array to store dynamic programming results
    vector<vector<int>> dpm;
    // Input array
    vector<int> arr;
    // Base value for indexing the dynamic programming array
    int base = 200 * 100 + 3;

    int dp(int i, int diff) {
        // If we have reached the end of the array, check if the difference is zero (indicating equal sum subsets)
        if (i == n)
            return diff == 0;
        
        // If the result for the current state has already been calculated, return it
        if (dpm[i][diff + base] != -1)
            return dpm[i][diff + base];
        
        // Recursively calculate the result by considering including the current element to the first or second set
        dpm[i][diff + base] = (dp(i + 1, diff + arr[i]) || dp(i + 1, diff - arr[i]));
        // Return the result for the current state
        return dpm[i][diff + base];
    }
    
    bool canPartition(vector<int>& nums) {
        // Copy the input array
        arr = nums;
        // Get the size of the input array
        n = nums.size();
        // Resize the dynamic programming array with appropriate dimensions and initialize with -1
        dpm.resize(n + 2, vector<int>(400 * 100 + 7, -1));
        
        // Call the helper function to start the dynamic programming process from the first element with a difference of 0
        return dp(0, 0);
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
    int n;
    vector<vector<int>> dpm;
    vector<int> arr;
    int base = 200 * 100 + 3;
    int dp(int i, int diff) {
        if (i == n)
            return diff == 0;
        if (dpm[i][diff + base] != -1)
            return dpm[i][diff + base];
        dpm[i][diff + base] = (dp(i + 1, diff + arr[i]) || dp(i + 1, diff - arr[i]));
        return dpm[i][diff + base];
    }
    bool canPartition(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        dpm.resize(n + 2, vector<int>(400 * 100 + 7, -1));
        return dp(0, 0);
    }
};
```
</details>
</li>
</ul>
