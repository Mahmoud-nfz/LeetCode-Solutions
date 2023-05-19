# Problem : House Robber

### Difficulty : **Medium**

https://leetcode.com/problems/house-robber/

---

### Tags : **dp**

### Relevant Tutorials :



---

# Statement

<p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and <b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p>

<p>Given an integer array <code>nums</code> representing the amount of money of each house, return <em>the maximum amount of money you can rob tonight <b>without alerting the police</b></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [2,7,9,3,1]
<strong>Output:</strong> 12
<strong>Explanation:</strong> Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 400</code></li>
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
    int rob(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();
        // Create a 2D array to store the dynamic programming results
        int dp[n+3][2];
        
        // Initialize the base case for not robbing the first house
        dp[0][0] = 0;
        // Initialize the base case for robbing the first house
        dp[0][1] = 0;
        
        for (int i = 1; i < nums.size() + 1; i++) {
            // Maximum amount without robbing the current house is the maximum of previous house robbing or not robbing
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            // Maximum amount with robbing the current house is the amount of current house plus the maximum amount without robbing the previous house
            dp[i][1] = nums[i-1] + dp[i-1][0];
        }
        
        // Return the maximum amount that can be robbed from the last house
        return max(dp[n][0], dp[n][1]);
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
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+3][2];
        dp[0][0] = 0;
        dp[0][1] = 0;
        for (int i = 1; i < nums.size() + 1; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = nums[i-1] + dp[i-1][0];
        }
        return max(dp[n][0], dp[n][1]);
    }
};
```
</details>
</li>
</ul>
