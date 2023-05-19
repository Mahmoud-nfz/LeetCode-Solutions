# Problem : Climbing Stairs

### Difficulty : **Easy**

https://leetcode.com/problems/climbing-stairs/

---

### Tags : **dp**

### Relevant Tutorials :



---

# Statement

<p>You are climbing a staircase. It takes <code>n</code> steps to reach the top.</p>

<p>Each time you can either climb <code>1</code> or <code>2</code> steps. In how many distinct ways can you climb to the top?</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> n = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 45</code></li>
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
    // Dynamic programming memoization array
    vector<int> dpm;

    // Recursive function to calculate the distinct ways to climb the stairs
    int dp(int n) {
        if (n <= 1)
            return 1;
        if (n == 2)
            return 2;
        if (dpm[n] != -1)
            return dpm[n];
        // Memoization to avoid redundant calculations
        dpm[n] = dp(n - 1) + dp(n - 2);
        return dpm[n];
    }

    int climbStairs(int n) {
        // Resize the memoization array to accommodate n+2 elements
        dpm.resize(n + 2);
        for (int i = 0; i < n + 2; i++) {
            // Initialize the memoization array with -1
            dpm[i] = -1;
        }
        // Call the dp function to get the distinct ways to climb the stairs
        return dp(n);
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
    vector<int> dpm;
    int dp(int n) {
        if (n <= 1)
            return 1;
        if (n == 2)
            return 2;
        if (dpm[n] != -1)
            return dpm[n];
        dpm[n] = dp(n - 1) + dp(n - 2);
        return dpm[n];
    }
    int climbStairs(int n) {
        dpm.resize(n + 2);
        for (int i = 0; i < n + 2; i++) {
            dpm[i] = -1;
        }
        return dp(n);
    }
};
```
</details>
</li>
</ul>
