# Problem : Permutation in String

### Difficulty : **Medium**

https://leetcode.com/problems/permutation-in-string/

---

### Tags : **sliding window, arrays**

### Relevant Tutorials :



---

# Statement

<p>Given two strings <code>s1</code> and <code>s2</code>, return <code>true</code><em> if </em><code>s2</code><em> contains a permutation of </em><code>s1</code><em>, or </em><code>false</code><em> otherwise</em>.</p>

<p>In other words, return <code>true</code> if one of <code>s1</code>'s permutations is the substring of <code>s2</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s1 = "ab", s2 = "eidbaooo"
<strong>Output:</strong> true
<strong>Explanation:</strong> s2 contains one permutation of s1 ("ba").
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s1 = "ab", s2 = "eidboaoo"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 10<sup>4</sup></code></li>
	<li><code>s1</code> and <code>s2</code> consist of lowercase English letters.</li>
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
    // Helper function to check if all character counts in the map are zero
    // which indicates a valid permutation match in the current window.
    bool check(map<char, int>& m) {
        bool chk = 1;
        for (auto p : m)
            chk &= p.second == 0;  // AND operation to ensure all counts are zero
        return chk;
    }

    // Main function to determine if s1's permutation is a substring of s2
    bool checkInclusion(string s1, string s2) {
        map<char, int> m; // Map to keep count of characters in s1

        // Populate the map with counts of each character in s1
        for (char c : s1) {
            m[c]++;
        }

        bool found = 0; // Boolean flag to indicate if a permutation has been found
        int i = 0, j = 0; // Pointers for sliding window: i (start), j (end)

        // Iterate through s2 with a sliding window
        while (j < s2.size()) {
            // If current char in s2 reduces the required count in the map
            if (m[s2[j]] > 0) {
                m[s2[j]]--;
                j++;
            } else if (i < j) {
                // If current char is not required or more than required,
                // move the start of the window to the right
                m[s2[i]]++;
                i++;
            } else {
                // If i == j and s2[j] is not in s1, skip this character
                i++;
                j++;
            }
            // Check if the current window is a valid permutation of s1
            found |= check(m);
        }

        // Final check for the last window after exiting the loop
        found |= check(m);

        return found;
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
    bool check(map<char, int>& m) {
        bool chk = 1;
        for (auto p : m)
            chk &= p.second == 0;  
        return chk;
    }
    bool checkInclusion(string s1, string s2) {
        map<char, int> m; 
        for (char c : s1) {
            m[c]++;
        }
        bool found = 0; 
        int i = 0, j = 0; 
        while (j < s2.size()) {
            if (m[s2[j]] > 0) {
                m[s2[j]]--;
                j++;
            } else if (i < j) {
                m[s2[i]]++;
                i++;
            } else {
                i++;
                j++;
            }
            found |= check(m);
        }
        found |= check(m);
        return found;
    }
};
```
</details>
</li>
</ul>
