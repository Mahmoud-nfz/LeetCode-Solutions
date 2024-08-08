# Problem : Combination Sum III

### Difficulty : **Medium**

https://leetcode.com/problems/combination-sum-iii/

---

### Tags : **dp, combinatorics**

### Relevant Tutorials :



---

# Statement

<p>Find all valid combinations of <code>k</code> numbers that sum up to <code>n</code> such that the following conditions are true:</p>

<ul>
	<li>Only numbers <code>1</code> through <code>9</code> are used.</li>
	<li>Each number is used <strong>at most once</strong>.</li>
</ul>

<p>Return <em>a list of all possible valid combinations</em>. The list must not contain the same combination twice, and the combinations may be returned in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> k = 3, n = 7
<strong>Output:</strong> [[1,2,4]]
<strong>Explanation:</strong>
1 + 2 + 4 = 7
There are no other valid combinations.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> k = 3, n = 9
<strong>Output:</strong> [[1,2,6],[1,3,5],[2,3,4]]
<strong>Explanation:</strong>
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> k = 4, n = 1
<strong>Output:</strong> []
<strong>Explanation:</strong> There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 &gt; 1, there are no valid combination.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= 9</code></li>
	<li><code>1 &lt;= n &lt;= 60</code></li>
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
    int target, k;
    
    // Function to get active bits from an integer mask; these represent the numbers included in a combination.
    vector<int> getActiveBits(unsigned int mask) {
        vector<int> activeBits;
        int position = 0;
        while (mask) {
            if (mask & 1) {
                // Position + 1 gives the actual number because bit positions are 0-indexed
                activeBits.push_back(position + 1);
            }
            mask >>= 1;
            position++;
        }
        return activeBits;
    }

    set<int> correctMasks;
    
    // Recursive function to explore all possible combinations using bit manipulation
    void dp(int i, int mask, int sum) {
        // Prune the recursion if the current sum exceeds the target or we have more numbers than needed
        if (sum > target || __builtin_popcount(mask) > k)
            return;
        
        // If current sum equals target and we used exactly k numbers, add the current mask to the set
        if (sum == target && __builtin_popcount(mask) == k) {
            correctMasks.insert(mask);
            return;
        }
        
        // If we've considered all numbers from 1 to 9, return
        if (i == 10)
            return;
        
        // Include the current number in the combination if it does not push the sum over the target
        if (sum + i <= target) {
            dp(i + 1, mask | (1 << (i - 1)), sum + i);
        }
        
        // Exclude the current number and move to the next
        dp(i + 1, mask, sum);
    }

    // Main function to initiate the DFS and collect the results
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->target = n;
        dp(1, 0, 0);  // Start the DFS with smallest number 1 and initial mask 0 and sum 0
        
        // Prepare the final result using the masks stored in correctMasks set
        vector<vector<int>> activeBitsVectors;
        for (unsigned int mask : correctMasks) {
            activeBitsVectors.pushback(getActiveBits(mask));
        }
        return activeBitsVectors;
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
    int target, k;
    vector<int> getActiveBits(unsigned int mask) {
        vector<int> activeBits;
        int position = 0;
        while (mask) {
            if (mask & 1) {
                activeBits.push_back(position + 1);
            }
            mask >>= 1;
            position++;
        }
        return activeBits;
    }
    set<int> correctMasks;
    void dp(int i, int mask, int sum) {
        if (sum > target || __builtin_popcount(mask) > k)
            return;
        if (sum == target && __builtin_popcount(mask) == k) {
            correctMasks.insert(mask);
            return;
        }
        if (i == 10)
            return;
        if (sum + i <= target) {
            dp(i + 1, mask | (1 << (i - 1)), sum + i);
        }
        dp(i + 1, mask, sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->target = n;
        dp(1, 0, 0);  
        vector<vector<int>> activeBitsVectors;
        for (unsigned int mask : correctMasks) {
            activeBitsVectors.pushback(getActiveBits(mask));
        }
        return activeBitsVectors;
    }
};
```
</details>
</li>
</ul>
