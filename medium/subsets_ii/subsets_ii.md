# Problem : Subsets II

### Difficulty : **Medium**

https://leetcode.com/problems/subsets-ii/

---

### Tags : **brute force, subsets**

### Relevant Tutorials :



---

# Statement

<p>Given an integer array <code>nums</code> that may contain duplicates, return <em>all possible</em> <span data-keyword="subset" class=" cursor-pointer relative text-dark-blue-s text-sm"><div class="popover-wrapper inline-block" data-headlessui-state=""><div><div aria-expanded="false" data-headlessui-state="" id="headlessui-popover-button-:r1r:"><div><em>subsets</em></div></div><div style="position: fixed; z-index: 40; inset: 0px auto auto 0px; transform: translate(99px, 200px);"></div></div></div></span><em> (the power set)</em>.</p>

<p>The solution set <strong>must not</strong> contain duplicate subsets. Return the solution in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,2,2]
<strong>Output:</strong> [[],[1],[1,2],[1,2,2],[2],[2,2]]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> [[],[0]]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10</code></li>
	<li><code>-10 &lt;= nums[i] &lt;= 10</code></li>
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Get the size of the input array.
        int n = nums.size();           
        // Initialize a bitset to 0 to represent subsets.
        int bitset = 0;                
        // Use a set to store unique subsets.
        set<vector<int>> ans;

        // Loop through all possible bitsets (subsets).
        while (bitset < (1 << n)) {
            // Create a vector to store the current subset.
            vector<int> currSet;
            for (int i = 0; i < n; i++) {
                // Check if the i-th bit of the bitset is set (1).
                // If so, add the corresponding element to the current subset.
                if ((bitset >> i) & 1) {
                    currSet.push_back(nums[i]);  
                }
            }
            // Sort the current subset elements in order to check if the subset is already present in a different order.
            sort(currSet.begin(), currSet.end()); 
            // Insert the sorted subset into the set.
            ans.insert(currSet);
            // Move to the next bitset.
            bitset++;
        }

        // Convert the result to a vector of vectors
        vector<vector<int>> result;
        for (const vector<int>& vec : ans) {
            result.push_back(vec);
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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();           
        int bitset = 0;                
        set<vector<int>> ans;
        while (bitset < (1 << n)) {
            vector<int> currSet;
            for (int i = 0; i < n; i++) {
                if ((bitset >> i) & 1) {
                    currSet.push_back(nums[i]);  
                }
            }
            sort(currSet.begin(), currSet.end()); 
            ans.insert(currSet);
            bitset++;
        }
        vector<vector<int>> result;
        for (const vector<int>& vec : ans) {
            result.push_back(vec);
        }
        return result;
    }
};
```
</details>
</li>
</ul>
