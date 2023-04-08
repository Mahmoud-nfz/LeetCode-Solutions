# Problem : Convert an Array Into a 2D Array With Conditions

### Difficulty : **Medium**

https://leetcode.com/contest/weekly-contest-339/problems/convert-an-array-into-a-2d-array-with-conditions/

---

### Tags : **data structures**

### Relevant Tutorials :



---

# Statement


<p>You are given an integer array <code>nums</code>. You need to create a 2D array from <code>nums</code> satisfying the following conditions:</p>

<ul>
	<li>The 2D array should contain <strong>only</strong> the elements of the array <code>nums</code>.</li>
	<li>Each row in the 2D array contains <strong>distinct</strong> integers.</li>
	<li>The number of rows in the 2D array should be <strong>minimal</strong>.</li>
</ul>

<p>Return <em>the resulting array</em>. If there are multiple answers, return any of them.</p>

<p><strong>Note</strong> that the 2D array can have a different number of elements on each row.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,3,4,1,2,3,1]
<strong>Output:</strong> [[1,3,4,2],[1,3],[1]]
<strong>Explanation:</strong> We can create a 2D array that contains the following rows:
- 1,3,4,2
- 1,3
- 1
All elements of nums were used, and each row of the 2D array contains distinct integers, so it is a valid answer.
It can be shown that we cannot have less than 3 rows in a valid array.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,4]
<strong>Output:</strong> [[4,3,2,1]]
<strong>Explanation:</strong> All elements of the array are distinct, so we can keep all of them in the first row of the 2D array.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 200</code></li>
	<li><code>1 &lt;= nums[i] &lt;= nums.length</code></li>
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
    The solution creates a 2D array from the input array satisfying the given conditions.
    It first creates a multiset and a vector to store the distinct integers and their frequencies respectively.
    It then iterates through the multiset until all the integers have been processed.
    In each iteration, it creates a temporary vector to store the distinct integers for a row.
    It adds an integer to the temporary vector only if it hasn't already been added.
    It then decreases the frequency of each integer in the temporary vector and removes it from the multiset if its frequency is 0.
    Finally, it adds the temporary vector to the resulting 2D array.
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        // Create a vector to store the frequency of each integer from the input array
        vector<int> freq(n+3);
        // Create a multiset to store the distinct integers from the input array
        multiset<int> s;
        // Traverse the input array
        for(auto x : nums){  
            s.insert(x);
            freq[x]++;
        }
        // Create a vector of vectors to store the resulting 2D array
        vector<vector<int>> ans;
        // Iterate until all the integers have been processed
        while(!s.empty()){
            int prev = -1;
            // Create a temporary vector to store the distinct integers for a row
            vector<int> temp;
            for(auto x : s){
                // If the integer is already in the temporary vector, skip it
                if(x == prev)
                    continue;
                prev = x;
                temp.push_back(x);
            }
            // Decrease the frequency of the integer and remove it from the multiset if its frequency is 0
            for(auto x : temp){
                freq[x]--;
                if(!freq[x])
                    s.erase(x);
            }
            // Add the temporary vector to the resulting 2D array
            ans.push_back(temp);
        }
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
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+3);
        multiset<int> s;
        for(auto x : nums){  
            s.insert(x);
            freq[x]++;
        }
        vector<vector<int>> ans;
        while(!s.empty()){
            int prev = -1;
            vector<int> temp;
            for(auto x : s){
                if(x == prev)
                    continue;
                prev = x;
                temp.push_back(x);
            }
            for(auto x : temp){
                freq[x]--;
                if(!freq[x])
                    s.erase(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
```
</details>
</li>
</ul>
