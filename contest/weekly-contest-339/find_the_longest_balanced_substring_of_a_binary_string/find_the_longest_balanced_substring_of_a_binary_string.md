# Problem : Find the Longest Balanced Substring of a Binary String

### Difficulty : **Easy**

https://leetcode.com/contest/weekly-contest-339/problems/find-the-longest-balanced-substring-of-a-binary-string/

---

### Tags : **arrays**

### Relevant Tutorials :



---

# Statement


<p>You are given a binary string <code>s</code> consisting only of zeroes and ones.</p>

<p>A substring of <code>s</code> is considered balanced if<strong> all zeroes are before ones</strong> and the number of zeroes is equal to the number of ones inside the substring. Notice that the empty substring is considered a balanced substring.</p>

<p>Return <em>the length of the longest balanced substring of </em><code>s</code>.</p>

<p>A <b>substring</b> is a contiguous sequence of characters within a string.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "01000111"
<strong>Output:</strong> 6
<strong>Explanation:</strong> The longest balanced substring is "000111", which has length 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "00111"
<strong>Output:</strong> 4
<strong>Explanation:</strong> The longest balanced substring is "0011", which has length 4.&nbsp;
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "111"
<strong>Output:</strong> 0
<strong>Explanation:</strong> There is no balanced substring except the empty substring, so the answer is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 50</code></li>
	<li><code>'0' &lt;= s[i] &lt;= '1'</code></li>
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
    The code uses a brute force approach to find all possible substrings of s, and then checks if each substring is balanced by counting the number of zeroes and ones.
    If a substring is balanced, the code updates the maximum length of balanced substrings seen so far.
    Finally, the code returns the maximum length of balanced substrings.

    Note that this solution has a time complexity of O(n^3), where n is the length of the input string s.
    Therefore, for large input sizes, this solution may take a long time to run.
    There are more efficient algorithms to solve this problem that have a lower time complexity.
*/

class Solution {
public:
    // Define a function to find the longest balanced substring in the binary string s
    int findTheLongestBalancedSubstring(string s) {
        // Initialize the maximum length of the balanced substring to be zero
        int ans = 0 ;
        // Loop through all possible pairs of starting and ending indices of substrings in s
        for(int i = 0 ; i < s.size() ; i ++){
            for(int j = i+1 ; j < s.size() ; j += 2){
                // Check if the substring is balanced by counting the number of zeroes and ones
                int x = 1 ;
                for(int k = i ; k <= (j+i)/2 ; k ++){
                    if(s[k] != '0')
                        x = 0 ;
                }
                for(int k = (j+i)/2 + 1 ; k <= j ; k ++){
                    if(s[k] != '1')
                        x = 0 ;
                }
                // If the substring is balanced, update the maximum length
                if(x)
                    ans = max(ans,j-i+1) ;
            }
        }
        // Return the maximum length of the balanced substring
        return ans ;
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
    int findTheLongestBalancedSubstring(string s) {
        int ans = 0 ;
        for(int i = 0 ; i < s.size() ; i ++){
            for(int j = i+1 ; j < s.size() ; j += 2){
                int x = 1 ;
                for(int k = i ; k <= (j+i)/2 ; k ++){
                    if(s[k] != '0')
                        x = 0 ;
                }
                for(int k = (j+i)/2 + 1 ; k <= j ; k ++){
                    if(s[k] != '1')
                        x = 0 ;
                }
                if(x)
                    ans = max(ans,j-i+1) ;
            }
        }
        return ans ;
    }
};
```
</details>
</li>
</ul>
