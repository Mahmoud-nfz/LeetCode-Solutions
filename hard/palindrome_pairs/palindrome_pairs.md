# Problem : Palindrome Pairs

### Difficulty : **Hard**

https://leetcode.com/problems/palindrome-pairs

---

### Tags : **hashing, strings**

### Relevant Tutorials :



---

# Statement

<p>You are given a <strong>0-indexed</strong> array of <strong>unique</strong> strings <code>words</code>.</p>

<p>A <strong>palindrome pair</strong> is a pair of integers <code>(i, j)</code> such that:</p>

<ul>
	<li><code>0 &lt;= i, j &lt; words.length</code>,</li>
	<li><code>i != j</code>, and</li>
	<li><code>words[i] + words[j]</code> (the concatenation of the two strings) is a <span data-keyword="palindrome-string" class=" cursor-pointer relative text-dark-blue-s text-sm"><div class="popover-wrapper inline-block" data-headlessui-state=""><div><div aria-expanded="false" data-headlessui-state="" id="headlessui-popover-button-:r11:"><div>palindrome</div></div><div style="position: fixed; z-index: 40; inset: 0px auto auto 0px; transform: translate(482px, 329px);"></div></div></div></span>.</li>
</ul>

<p>Return <em>an array of all the <strong>palindrome pairs</strong> of </em><code>words</code>.</p>

<p>You must write an algorithm with&nbsp;<code>O(sum of words[i].length)</code>&nbsp;runtime complexity.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> words = ["abcd","dcba","lls","s","sssll"]
<strong>Output:</strong> [[0,1],[1,0],[3,2],[2,4]]
<strong>Explanation:</strong> The palindromes are ["abcddcba","dcbaabcd","slls","llssssll"]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> words = ["bat","tab","cat"]
<strong>Output:</strong> [[0,1],[1,0]]
<strong>Explanation:</strong> The palindromes are ["battab","tabbat"]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> words = ["a",""]
<strong>Output:</strong> [[0,1],[1,0]]
<strong>Explanation:</strong> The palindromes are ["a","a"]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 5000</code></li>
	<li><code>0 &lt;= words[i].length &lt;= 300</code></li>
	<li><code>words[i]</code> consists of lowercase English letters.</li>
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
    // Macros for common tasks, enhancing readability.
    #define fr(i,a,b) for(int i = a ; i < b ; i++)
    #define pb push_back
    typedef long long ll;

    // Constants for the hash function.
    const int p = 31;
    const int m = 1e9 + 9;

    // Computes the hash of a string based on each character's position and value.
    long long compute_hash(string const& s) {
        long long hash_value = 0;
        long long p_pow = 1;
        for (char c : s) {
            // Incremental hash computation
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }

    // Helper function to determine if a substring is a palindrome.
    bool isPalindrome(string& s, int start, int end) {
        while(start < end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    // Main function to find all palindrome pairs in the given list of words.
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        // Maps to store the forward and reverse hashes of all words.
        map<ll, int> forwardHashes, reverseHashes;

        // Populate the hash maps.
        fr(i,0,n){
            forwardHashes[compute_hash(words[i])] = i;   
            reverse(words[i].begin(), words[i].end());
            reverseHashes[compute_hash(words[i])] = i;
        }

        vector<vector<int>> pairs;
        fr(i,0,n){
            long long hash_value = 0;
            long long p_pow = 1;
            // Check potential pairs by examining each prefix of the current word.
            fr(j,0,words[i].size()){
                if(forwardHashes.count(hash_value) && isPalindrome(words[i], j, words[i].size()-1)){
                    if(forwardHashes[hash_value] != i)
                        pairs.pb({forwardHashes[hash_value], i});
                }
                char c = words[i][j];
                hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
                p_pow = (p_pow * p) % m;
            }
            // Check if the whole word can form a pair with an empty string or similar case.
            if(forwardHashes.count(hash_value)){
                if(forwardHashes[hash_value] != i)
                    pairs.pb({forwardHashes[hash_value], i});
            }

            // Repeat the check for reversed strings.
            reverse(words[i].begin(), words[i].end());
            hash_value = 0;
            p_pow = 1;
            fr(j,0,words[i].size()){
                if(reverseHashes.count(hash_value) && isPalindrome(words[i], j, words[i].size()-1)){
                    if(reverseHashes[hash_value] != i)
                        pairs.pb({i, reverseHashes[hash_value]});
                }
                char c = words[i][j];
                hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
                p_pow = (p_pow * p) % m;
            }
        }

        return pairs;
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
    #define fr(i,a,b) for(int i = a ; i < b ; i++)
    #define pb push_back
    typedef long long ll;
    const int p = 31;
    const int m = 1e9 + 9;
    long long compute_hash(string const& s) {
        long long hash_value = 0;
        long long p_pow = 1;
        for (char c : s) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }
    bool isPalindrome(string& s, int start, int end) {
        while(start < end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        map<ll, int> forwardHashes, reverseHashes;
        fr(i,0,n){
            forwardHashes[compute_hash(words[i])] = i;   
            reverse(words[i].begin(), words[i].end());
            reverseHashes[compute_hash(words[i])] = i;
        }
        vector<vector<int>> pairs;
        fr(i,0,n){
            long long hash_value = 0;
            long long p_pow = 1;
            fr(j,0,words[i].size()){
                if(forwardHashes.count(hash_value) && isPalindrome(words[i], j, words[i].size()-1)){
                    if(forwardHashes[hash_value] != i)
                        pairs.pb({forwardHashes[hash_value], i});
                }
                char c = words[i][j];
                hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
                p_pow = (p_pow * p) % m;
            }
            if(forwardHashes.count(hash_value)){
                if(forwardHashes[hash_value] != i)
                    pairs.pb({forwardHashes[hash_value], i});
            }
            reverse(words[i].begin(), words[i].end());
            hash_value = 0;
            p_pow = 1;
            fr(j,0,words[i].size()){
                if(reverseHashes.count(hash_value) && isPalindrome(words[i], j, words[i].size()-1)){
                    if(reverseHashes[hash_value] != i)
                        pairs.pb({i, reverseHashes[hash_value]});
                }
                char c = words[i][j];
                hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
                p_pow = (p_pow * p) % m;
            }
        }
        return pairs;
    }
};
```
</details>
</li>
</ul>
