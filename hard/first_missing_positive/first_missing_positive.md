# Problem : First Missing Positive

### Difficulty : **Hard**

https://leetcode.com/problems/first-missing-positive/

---

### Tags : **arrays**

### Relevant Tutorials :



---

# Statement

<p>Given an unsorted integer array <code>nums</code>, return the smallest missing positive integer.</p>

<p>You must implement an algorithm that runs in <code>O(n)</code> time and uses <code>O(1)</code> auxiliary space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,0]
<strong>Output:</strong> 3
<strong>Explanation:</strong> The numbers in the range [1,2] are all in the array.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [3,4,-1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 1 is in the array but 2 is missing.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [7,8,9,11,12]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The smallest positive integer 1 is missing.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
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
    int firstMissingPositive(vector<int>& nums) {
        // Create an unordered set to store the present integers.
        unordered_set<int> present; 

        // Iterate through the input array and insert each integer into the set.
        for(auto x: nums){
            present.insert(x);
        }

        // Iterate through positive integers from 1 to (nums.size() + 1).
        for(int i = 1 ; i < nums.size() + 2 ; i++){
            // Check if the current positive integer is not in the set (missing).
            // Return the first missing positive integer found.
            if(present.find(i) == present.end()){
                return i; 
            }
        }
        // If all positive integers are present, return the next positive integer.
        return nums.size() + 1;
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
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> present; 
        for(auto x: nums){
            present.insert(x);
        }
        for(int i = 1 ; i < nums.size() + 2 ; i++){
            if(present.find(i) == present.end()){
                return i; 
            }
        }
        return nums.size() + 1;
    }
};
```
</details>
</li>
</ul>
