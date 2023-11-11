# Problem : Decode Ways

### Difficulty : **Medium**

https://leetcode.com/problems/decode-ways/

---

### Tags : **dp**

### Relevant Tutorials :



---

# Statement

<p>A message containing letters from <code>A-Z</code> can be <strong>encoded</strong> into numbers using the following mapping:</p>

<pre>'A' -&gt; "1"
'B' -&gt; "2"
...
'Z' -&gt; "26"
</pre>

<p>To <strong>decode</strong> an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, <code>"11106"</code> can be mapped into:</p>

<ul>
	<li><code>"AAJF"</code> with the grouping <code>(1 1 10 6)</code></li>
	<li><code>"KJF"</code> with the grouping <code>(11 10 6)</code></li>
</ul>

<p>Note that the grouping <code>(1 11 06)</code> is invalid because <code>"06"</code> cannot be mapped into <code>'F'</code> since <code>"6"</code> is different from <code>"06"</code>.</p>

<p>Given a string <code>s</code> containing only digits, return <em>the <strong>number</strong> of ways to <strong>decode</strong> it</em>.</p>

<p>The test cases are generated so that the answer fits in a <strong>32-bit</strong> integer.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "12"
<strong>Output:</strong> 2
<strong>Explanation:</strong> "12" could be decoded as "AB" (1 2) or "L" (12).
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "226"
<strong>Output:</strong> 3
<strong>Explanation:</strong> "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "06"
<strong>Output:</strong> 0
<strong>Explanation:</strong> "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> contains only digits and may contain leading zero(s).</li>
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
    vector<int> dpm; // Dynamic programming array for memoization

    int dp(string& s, int i) {
        // If this state is already computed, return the cached result
        if (dpm[i] != -1) 
            return dpm[i];

        // If we've reached the end of the string, we've found one valid decoding
        if (i == s.size()) 
            return 1;

        // If we are at the second last character of the string, If it's not '0', it can be decoded into a single character
        if (i == s.size() - 1) 
            return s[i] != '0'; 

        // If the current character is '0', it can't be decoded by itself
        if (s[i] == '0')
            return 0;

        // Temporary variable to store the result of this state
        int temp = 0; 

        // Recursively decode the string considering the current character as a single digit
        temp += dp(s, i + 1);

        // Check if the current character and the next character can be combined into a valid two-digit code
        int curr = (s[i] - '0') * 10 + (s[i + 1] - '0');

        // Check if the two digits form a valid code (between 10 and 26)
        if (curr > 9 && curr < 27) 
            // Recursively decode the string with these two digits as a single unit
            temp += dp(s, i + 2); 

        // Store the computed result in the memoization array
        return dpm[i] = temp;
    }

    int numDecodings(string s) {
        // Initialize the DP array with -1 (uncomputed) for each index
        dpm.resize(s.size() + 1, -1); 
        // Start the dynamic programming process from the beginning of the string
        return dp(s, 0); 
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
    vector<int> dpm; 
    int dp(string& s, int i) {
        if (dpm[i] != -1) 
            return dpm[i];
        if (i == s.size()) 
            return 1;
        if (i == s.size() - 1) 
            return s[i] != '0'; 
        if (s[i] == '0')
            return 0;
        int temp = 0; 
        temp += dp(s, i + 1);
        int curr = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (curr > 9 && curr < 27) 
            temp += dp(s, i + 2); 
        return dpm[i] = temp;
    }
    int numDecodings(string s) {
        dpm.resize(s.size() + 1, -1); 
        return dp(s, 0); 
    }
};
```
</details>
</li>
</ul>
