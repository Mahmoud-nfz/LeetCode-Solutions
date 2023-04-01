# Problem : Find the Substring With Maximum Cost

### Difficulty : **Medium**

https://leetcode.com/contest/biweekly-contest-101/problems/find-the-substring-with-maximum-cost/

---

### Tags : **arrays**

### Relevant Tutorials :



---

# Statement


<p>You are given a string <code>s</code>, a string <code>chars</code> of <strong>distinct</strong> characters and an integer array <code>vals</code> of the same length as <code>chars</code>.</p>

<p>The <strong>cost of the substring </strong>is the sum of the values of each character in the substring. The cost of an empty string is considered <code>0</code>.</p>

<p>The <strong>value of the character </strong>is defined in the following way:</p>

<ul>
	<li>If the character is not in the string <code>chars</code>, then its value is its corresponding position <strong>(1-indexed)</strong> in the alphabet.

	<ul>
		<li>For example, the value of <code>'a'</code> is <code>1</code>, the value of <code>'b'</code> is <code>2</code>, and so on. The value of <code>'z'</code> is <code>26</code>.</li>
	</ul>
	</li>
	<li>Otherwise, assuming <code>i</code> is the index where the character occurs in the string <code>chars</code>, then its value is <code>vals[i]</code>.</li>
</ul>

<p>Return <em>the maximum cost among all substrings of the string</em> <code>s</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "adaa", chars = "d", vals = [-1000]
<strong>Output:</strong> 2
<strong>Explanation:</strong> The value of the characters "a" and "d" is 1 and -1000 respectively.
The substring with the maximum cost is "aa" and its cost is 1 + 1 = 2.
It can be proven that 2 is the maximum cost.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abc", chars = "abc", vals = [-1,-1,-1]
<strong>Output:</strong> 0
<strong>Explanation:</strong> The value of the characters "a", "b" and "c" is -1, -1, and -1 respectively.
The substring with the maximum cost is the empty substring "" and its cost is 0.
It can be proven that 0 is the maximum cost.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> consist of lowercase English letters.</li>
	<li><code>1 &lt;= chars.length &lt;= 26</code></li>
	<li><code>chars</code> consist of <strong>distinct</strong> lowercase English letters.</li>
	<li><code>vals.length == chars.length</code></li>
	<li><code>-1000 &lt;= vals[i] &lt;= 1000</code></li>
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
    // Define a function to calculate the maximum subarray sum
    int SubarrayWithMaxSum(vector<int>& nums)
    {
        // Initialize currMax and globalMax with first value of nums
        int endIndex, currMax = nums[0];
        int globalMax = nums[0];
 
        // Iterate for all the elements of the array
        for (int i = 1; i < nums.size(); ++i) {
 
            // Update currMax
            currMax = max(nums[i], nums[i] + currMax);
 
            // Check if currMax is greater than globalMax
            if (currMax > globalMax) {
                globalMax = currMax;
                endIndex = i;
            }
        }
        // Set the start index to end index
        int startIndex = endIndex;
        // Return the maximum sum
        return globalMax ;
    }
    
    // Define a function to calculate the maximum cost substring
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        // Define an array to store the cost of each character
        int cost[30] ;
        // Initialize the cost array with the position of each character
        for(int i = 0 ; i < 28 ; i ++){
            cost[i] = i+1 ;
        }
        // Update the cost of each character present in string chars
        for(int i = 0 ; i < chars.size() ; i ++){
            cost[chars[i]-'a'] = vals[i] ;
        }
        // Define a vector to store the cost of each character in the string s
        vector<int> v ;
        // Calculate the cost of each character in the string s using the cost array
        for(auto c : s){
            v.push_back(cost[c-'a']) ;
        }
        // Calculate the maximum subarray sum of the vector v to get the maximum cost substring
        int x = SubarrayWithMaxSum(v) ;
        // Return the maximum cost substring or 0 if all substrings have negative cost
        return max(x,0) ;
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
    int SubarrayWithMaxSum(vector<int>& nums)
    {
        int endIndex, currMax = nums[0];
        int globalMax = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            currMax = max(nums[i], nums[i] + currMax);
            if (currMax > globalMax) {
                globalMax = currMax;
                endIndex = i;
            }
        }
        int startIndex = endIndex;
        return globalMax ;
    }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int cost[30] ;
        for(int i = 0 ; i < 28 ; i ++){
            cost[i] = i+1 ;
        }
        for(int i = 0 ; i < chars.size() ; i ++){
            cost[chars[i]-'a'] = vals[i] ;
        }
        vector<int> v ;
        for(auto c : s){
            v.push_back(cost[c-'a']) ;
        }
        int x = SubarrayWithMaxSum(v) ;
        return max(x,0) ;
    }
};
```
</details>
</li>
</ul>
