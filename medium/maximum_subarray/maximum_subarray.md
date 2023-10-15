# Problem : Maximum Subarray

### Difficulty : **Medium**

https://leetcode.com/problems/maximum-subarray/

---

### Tags : **arrays, dp**

### Relevant Tutorials :



---

# Statement

<p>Given an integer array <code>nums</code>, find the <span data-keyword="subarray-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><div class="popover-wrapper inline-block" data-headlessui-state=""><div><div aria-expanded="false" data-headlessui-state="" id="headlessui-popover-button-:r54:"><div>subarray</div></div><div style="position: fixed; z-index: 40; inset: 0px auto auto 0px; transform: translate(285px, 179px);"></div></div></div></span> with the largest sum, and return <em>its sum</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The subarray [4,-1,2,1] has the largest sum 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The subarray [1] has the largest sum 1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [5,4,-1,7,8]
<strong>Output:</strong> 23
<strong>Explanation:</strong> The subarray [5,4,-1,7,8] has the largest sum 23.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution using the <strong>divide and conquer</strong> approach, which is more subtle.</p>


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
    int maxSubArray(vector<int>& nums) {
        // Initialize two variables to keep track of the maximum sum so far and the current sum
        int maxSoFar = -1e5; // Initialize to a very small value (negative infinity)
        int curr = 0; // Initialize the current sum to 0

        int n = nums.size(); // Get the size of the input array

        // Iterate through the input array to find the maximum subarray sum
        for (int i = 0; i < n; i++) {
            curr += nums[i]; // Add the current element to the current sum

            // Update maxSoFar to be the maximum of the previous maxSoFar and the current sum
            maxSoFar = max(maxSoFar, curr);

            // If the current sum becomes negative, reset it to 0, as it doesn't contribute to the maximum subarray sum
            if (curr < 0) {
                curr = 0;
            }
        }

        // Return the maximum subarray sum found
        return maxSoFar;
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
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = -1e5; 
        int curr = 0; 
        int n = nums.size(); 
        for (int i = 0; i < n; i++) {
            curr += nums[i]; 
            maxSoFar = max(maxSoFar, curr);
            if (curr < 0) {
                curr = 0;
            }
        }
        return maxSoFar;
    }
};
```
</details>
</li>
</ul>
