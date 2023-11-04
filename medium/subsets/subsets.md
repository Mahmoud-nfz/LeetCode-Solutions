# Problem : Subsets

### Difficulty : **Medium**

https://leetcode.com/problems/subsets/

---

### Tags : **brute force, subsets**

### Relevant Tutorials :



---

# Statement

<p>Given an integer array <code>nums</code> of <strong>unique</strong> elements, return <em>all possible</em> <span data-keyword="subset" class=" cursor-pointer relative text-dark-blue-s text-sm"><div class="popover-wrapper inline-block" data-headlessui-state=""><div><div aria-expanded="false" data-headlessui-state="" id="headlessui-popover-button-:r33:"><div><em>subsets</em></div></div><div style="position: fixed; z-index: 40; inset: 0px auto auto 0px; transform: translate(466px, 179px);"></div></div></div></span> <em>(the power set)</em>.</p>

<p>The solution set <strong>must not</strong> contain duplicate subsets. Return the solution in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> [[],[0]]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
	<li>All the numbers of&nbsp;<code>nums</code> are <strong>unique</strong>.</li>
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
    vector<vector<int>> subsets(vector<int>& nums) {
        // Get the number of unique elements in the input array
        int n = nums.size();
        // Initialize a bitset to represent subsets, the i-th bit is active means that we include the i-th element of the array in the current subset
        int bitset = 0; 
        // Initialize a vector to store the resulting subsets
        vector<vector<int>> ans; 

        // Iterate through all possible bitsets
        while (bitset < (1 << n)) { 
            // Create a vector to store the current subset
            vector<int> currSet; 

            for (int i = 0; i < n; i++) {
                // Check if the i-th bit is set in the bitset
                // If so, add the corresponding element to the current subset
                if ((bitset >> i) & 1) 
                    currSet.push_back(nums[i]); 
            }

            // Add the current subset to the result vector
            ans.push_back(currSet); 
            // Increment the bitset to consider the next subset
            bitset++; 
        }

        // Return the vector containing all unique subsets
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
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int bitset = 0; 
        vector<vector<int>> ans; 
        while (bitset < (1 << n)) { 
            vector<int> currSet; 
            for (int i = 0; i < n; i++) {
                if ((bitset >> i) & 1) 
                    currSet.push_back(nums[i]); 
            }
            ans.push_back(currSet); 
            bitset++; 
        }
        return ans; 
    }
};
```
</details>
</li>
</ul>
