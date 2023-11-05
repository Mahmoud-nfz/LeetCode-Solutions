# Problem : Minimum Window Substring

### Difficulty : **Hard**

https://leetcode.com/problems/minimum-window-substring/

---

### Tags : **Sliding window, strings**

### Relevant Tutorials :



---

# Statement

<p>Given two strings <code>s</code> and <code>t</code> of lengths <code>m</code> and <code>n</code> respectively, return <em>the <strong>minimum window</strong></em> <span data-keyword="substring-nonempty" class=" cursor-pointer relative text-dark-blue-s text-sm"><div class="popover-wrapper inline-block" data-headlessui-state=""><div><div aria-expanded="false" data-headlessui-state="" id="headlessui-popover-button-:r1r:"><div><strong><em>substring</em></strong></div></div><div style="position: fixed; z-index: 40; inset: 0px auto auto 0px; transform: translate(56px, 200px);"></div></div></div></span><em> of </em><code>s</code><em> such that every character in </em><code>t</code><em> (<strong>including duplicates</strong>) is included in the window</em>. If there is no such substring, return <em>the empty string </em><code>""</code>.</p>

<p>The testcases will be generated such that the answer is <strong>unique</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "ADOBECODEBANC", t = "ABC"
<strong>Output:</strong> "BANC"
<strong>Explanation:</strong> The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "a", t = "a"
<strong>Output:</strong> "a"
<strong>Explanation:</strong> The entire string s is the minimum window.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "a", t = "aa"
<strong>Output:</strong> ""
<strong>Explanation:</strong> Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == s.length</code></li>
	<li><code>n == t.length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> and <code>t</code> consist of uppercase and lowercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you find an algorithm that runs in <code>O(m + n)</code> time?</p>


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
    string minWindow(string s, string t) {
        if (!t.size())
            return "";

        int i = 0, j = 0;

        // Initialize two vectors to keep track of the characters needed and the original characters in string t
        vector<int> needed(130, 0), original(130, 0);

        // Populate the needed and original vectors with the characters from string t
        for (auto c : t)
            needed[c]++, original[c]++;

        int remToComplete = 0;

        // Calculate the number of unique characters needed
        for (auto x : needed)
            remToComplete += x != 0;

        int ansi = -1, ansj = -1;

        while (j < s.size()) {
            if (original[s[j]]) {
                needed[s[j]]--;
                if (needed[s[j]] == 0)
                    remToComplete--;
            }
            j++;

            while (i < j) {
                if (!original[s[i])
                    i++;
                else if (needed[s[i]] < 0) {
                    needed[s[i]]++;
                    if (needed[s[i]] == 1)
                        remToComplete++;
                    i++;
                } else
                    break;
            }

            // Check if all required characters are found and if the current window is smaller than the previous answer
            if (remToComplete == 0 && ((ansi == -1) || (j - i < ansj - ansi)) {
                ansj = j;
                ansi = i;
            }
        }

        if (ansi == -1)
            return "";
        else
            return s.substr(ansi, ansj - ansi);
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
    string minWindow(string s, string t) {
        if (!t.size())
            return "";
        int i = 0, j = 0;
        vector<int> needed(130, 0), original(130, 0);
        for (auto c : t)
            needed[c]++, original[c]++;
        int remToComplete = 0;
        for (auto x : needed)
            remToComplete += x != 0;
        int ansi = -1, ansj = -1;
        while (j < s.size()) {
            if (original[s[j]]) {
                needed[s[j]]--;
                if (needed[s[j]] == 0)
                    remToComplete--;
            }
            j++;
            while (i < j) {
                if (!original[s[i])
                    i++;
                else if (needed[s[i]] < 0) {
                    needed[s[i]]++;
                    if (needed[s[i]] == 1)
                        remToComplete++;
                    i++;
                } else
                    break;
            }
            if (remToComplete == 0 && ((ansi == -1) || (j - i < ansj - ansi)) {
                ansj = j;
                ansi = i;
            }
        }
        if (ansi == -1)
            return "";
        else
            return s.substr(ansi, ansj - ansi);
    }
};
```
</details>
</li>
</ul>
