# Problem : Max Consecutive Ones III

### Difficulty : **Medium**

https://leetcode.com/problems/max-consecutive-ones-iii/

---

### Tags : **arrays, dp**

### Relevant Tutorials :



---

# Statement

<p>Given a binary array <code>nums</code> and an integer <code>k</code>, return <em>the maximum number of consecutive </em><code>1</code><em>'s in the array if you can flip at most</em> <code>k</code> <code>0</code>'s.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong> [1,1,1,0,0,<u><strong>1</strong>,1,1,1,1,<strong>1</strong></u>]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
<strong>Output:</strong> 10
<strong>Explanation:</strong> [0,0,<u>1,1,<strong>1</strong>,<strong>1</strong>,1,1,1,<strong>1</strong>,1,1</u>,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
	<li><code>0 &lt;= k &lt;= nums.length</code></li>
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
    int longestOnes(vector<int>& nums, int k) {
        // This vector will store the indices of all zeros in the array
        vector<int> zeros;
        // This will keep track of the index in the zeros vector
        int zidx = 0;
        
        // Loop through the array and record the indices of zeros
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                zeros.push_back(i);
        }

        // Count of zeros that have been flipped
        int zerosChanged = 0;
        // Two pointers defining the current window of 1s potentially including some flipped 0s
        int l = 0, r = 0;
        // This will store the maximum number of consecutive ones found
        int ans = 0;
        
        // Main loop through the array
        while(r < nums.size()) {
            // Update the answer each iteration to ensure it includes cases where the loop ends without another update
            ans = max(ans, r - l);
            
            if(nums[r] == 1) {
                // If current number is 1, just expand the right end of the window
                r++;
            } else { // If current number is 0
                if(zerosChanged < k) {
                    // If we have not exhausted our quota of flips
                    r++; // Expand the window
                    zerosChanged++; // Use up one of our allowed flips
                } else { 
                    // If we have exhausted our flips
                    r++; // Still expand the window
                    // Move the left end of the window to one past the oldest zero in the current window
                    l = zeros[zidx] + 1;
                    // Move to the next zero in the list
                    zidx++; 
                }
            }
        }

        // Final check to update the answer in case the longest sequence is at the end of the array
        ans = max(ans, r - l);

        // Return the maximum length found
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
    int longestOnes(vector<int>& nums, int k) {
        vector<int> zeros;
        int zidx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                zeros.push_back(i);
        }
        int zerosChanged = 0;
        int l = 0, r = 0;
        int ans = 0;
        while(r < nums.size()) {
            ans = max(ans, r - l);
            if(nums[r] == 1) {
                r++;
            } else { 
                if(zerosChanged < k) {
                    r++; 
                    zerosChanged++; 
                } else { 
                    r++; 
                    l = zeros[zidx] + 1;
                    zidx++; 
                }
            }
        }
        ans = max(ans, r - l);
        return ans;
    }
};
```
</details>
</li>
</ul>
