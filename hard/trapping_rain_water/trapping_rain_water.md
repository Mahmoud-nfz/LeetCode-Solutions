# Problem : Trapping Rain Water

### Difficulty : **Hard**

https://leetcode.com/problems/trapping-rain-water/

---

### Tags : **arrays**

### Relevant Tutorials :



---

# Statement

<p>Given <code>n</code> non-negative integers representing an elevation map where the width of each bar is <code>1</code>, compute how much water it can trap after raining.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png" style="width: 412px; height: 161px;">
<pre><strong>Input:</strong> height = [0,1,0,2,1,0,1,3,2,1,2,1]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> height = [4,2,0,3,2,5]
<strong>Output:</strong> 9
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>1 &lt;= n &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>5</sup></code></li>
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
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> ans(n, 0);

        // Step 1: Calculate the highest bar to the left of each position
        int highestSoFar = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] < highestSoFar) {
                ans[i] = highestSoFar;
            } else {
                ans[i] = height[i];
                highestSoFar = height[i];
            }
        }

        // Step 2: Calculate the highest bar to the right of each position
        highestSoFar = 0;
        for (int i = n - 1; i >= 0; i--) {
            highestSoFar = max(height[i], highestSoFar);
            ans[i] = min(ans[i], highestSoFar);
        }

        // Step 3: Calculate the amount of trapped water
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += ans[i] - height[i];
        }

        return result;
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
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> ans(n, 0);
        int highestSoFar = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] < highestSoFar) {
                ans[i] = highestSoFar;
            } else {
                ans[i] = height[i];
                highestSoFar = height[i];
            }
        }
        highestSoFar = 0;
        for (int i = n - 1; i >= 0; i--) {
            highestSoFar = max(height[i], highestSoFar);
            ans[i] = min(ans[i], highestSoFar);
        }
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += ans[i] - height[i];
        }
        return result;
    }
};
```
</details>
</li>
</ul>
