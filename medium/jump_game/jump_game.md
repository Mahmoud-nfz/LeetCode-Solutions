# Problem : Jump Game

### Difficulty : **Medium**

https://leetcode.com/problems/jump-game/

---

### Tags : **dp**

### Relevant Tutorials :



---

# Statement

<p>You are given an integer array <code>nums</code>. You are initially positioned at the array's <strong>first index</strong>, and each element in the array represents your maximum jump length at that position.</p>

<p>Return <code>true</code><em> if you can reach the last index, or </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,1,1,4]
<strong>Output:</strong> true
<strong>Explanation:</strong> Jump 1 step from index 0 to 1, then 3 steps to the last index.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,2,1,0,4]
<strong>Output:</strong> false
<strong>Explanation:</strong> You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
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
/*

Solution: We can use dynamic programming to solve this problem.
Let's define a boolean array called possible where possible[i] represents whether we can jump from the ith index to the last index.
We start with possible[n-1] = true since we are already at the last index.
Then, we move backwards in the array from n-2 to 0, and for each index i, we determine whether we can jump to the last index from that index.

To determine if we can jump from index i, we look at all the indices we can jump to from index i, and check if any of those indices are possible.
We can keep track of the possible indices using a suffix sum. suffix_sum[i] represents the number of indices we can jump to from i that are possible.
We can compute this by summing possible[i+1] to possible[n-1], and adding one for each possible[i+1] (since we can jump from i to i+1 and i+1 is possible).

Once we have the suffix sum, we can determine whether we can jump from i by checking if suffix_sum[i+1] - suffix_sum[min(n,i+nums[i]+1)] is greater than 0. If this is true, it means we can jump to a possible index from i, so we set possible[i] to true. We then update suffix_sum[i] to be the sum of suffix_sum[i+1] and possible[i].

Finally, we return whether we can jump from index 0, i.e., whether possible[0] is true.

Time Complexity: O(n), where n is the length of the input array.
Space Complexity: O(n), for the two arrays possible and suffix_sum.

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> possible(n,0), suffix_sum (n+1,0) ;
        
        // Base case
        possible[n-1] = 1 ;
        suffix_sum[n-1] = 1 ;
        
        // Loop from n-2 to 0
        for(int i = n-2 ; i >= 0 ; i --){
            // Determine whether we can jump to the last index from index i
            possible[i] = suffix_sum[i+1] - suffix_sum[min(n,i+nums[i]+1)] > 0 ;
            
            // Update suffix_sum[i] using possible[i]
            suffix_sum[i] = suffix_sum[i+1] + possible[i] ;
        }
        
        // Return whether we can jump from index 0 to the last index
        return possible[0] == 1 ;
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
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> possible(n,0), suffix_sum (n+1,0) ;
        possible[n-1] = 1 ;
        suffix_sum[n-1] = 1 ;
        for(int i = n-2 ; i >= 0 ; i --){
            possible[i] = suffix_sum[i+1] - suffix_sum[min(n,i+nums[i]+1)] > 0 ;
            suffix_sum[i] = suffix_sum[i+1] + possible[i] ;
        }
        return possible[0] == 1 ;
    }
};
```
</details>
</li>
</ul>
