# Problem : Word Search

### Difficulty : **Medium**

https://leetcode.com/problems/word-search/

---

### Tags : **matrices, backtracking**

### Relevant Tutorials :



---

# Statement

<p>Given an <code>m x n</code> grid of characters <code>board</code> and a string <code>word</code>, return <code>true</code> <em>if</em> <code>word</code> <em>exists in the grid</em>.</p>

<p>The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word2.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 3:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/15/word3.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == board.length</code></li>
	<li><code>n = board[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 6</code></li>
	<li><code>1 &lt;= word.length &lt;= 15</code></li>
	<li><code>board</code> and <code>word</code> consists of only lowercase and uppercase English letters.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you use search pruning to make your solution faster with a larger <code>board</code>?</p>


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
    // Helper function to check if 's' is a prefix of 't'
    bool isPrefix(const std::string& t, const std::string& s) {
        // Check if the length of string 's' is greater than the length of string 't'
        if (s.length() > t.length()) {
            return false;
        }

        // Iterate through the characters of 's' and compare them to the corresponding characters in 't'
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] != t[i]) {
                return false; // If any character doesn't match, 's' is not a prefix of 't'
            }
        }

        // If we reach this point, all characters in 's' matched the corresponding characters in 't'
        return true; // 's' is a prefix of 't'
    }

    string target;
    vector<vector<bool>> visited;
    int n, m;

    // Depth-First Search (DFS) function to explore the grid
    int dfs(vector<vector<char>>& board, string& curr, int i, int j) {
        curr += board[i][j];

        // Check if the current substring matches the target word
        if (curr == target)
            return true;
        
        // Check if the current substring is a prefix of the target word
        if (!isPrefix(target, curr)) {
            curr.pop_back();
            return 0;
        }
        
        visited[i][j] = true;

        // Recursively explore adjacent cells
        if (i > 0 && !visited[i - 1][j])
            if (dfs(board, curr, i - 1, j))
                return true;
        if (j > 0 && !visited[i][j - 1])
            if (dfs(board, curr, i, j - 1))
                return true;
        if (i < n - 1 && !visited[i + 1][j])
            if (dfs(board, curr, i + 1, j))
                return true;
        if (j < m - 1 && !visited[i][j + 1])
            if (dfs(board, curr, i, j + 1))
                return true;
        
        curr.pop_back();
        visited[i][j] = false;

        return 0;
    }

    // Helper function to reset the 'visited' grid
    void resetVisited() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = 0;
            }
        }
    }

    // Main function to search for the target word in the grid
    bool exist(vector<vector<char>>& board, string word) {
        target = word;
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> v(n, vector<bool>(m, 0));
        visited = v;

        string curr;
        
        // Loop through each cell in the grid to start DFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                resetVisited();
                curr = "";
                if (dfs(board, curr, i, j))
                    return true;
            }
        }
        return false;
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
    bool isPrefix(const std::string& t, const std::string& s) {
        if (s.length() > t.length()) {
            return false;
        }
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] != t[i]) {
                return false; 
            }
        }
        return true; 
    }
    string target;
    vector<vector<bool>> visited;
    int n, m;
    int dfs(vector<vector<char>>& board, string& curr, int i, int j) {
        curr += board[i][j];
        if (curr == target)
            return true;
        if (!isPrefix(target, curr)) {
            curr.pop_back();
            return 0;
        }
        visited[i][j] = true;
        if (i > 0 && !visited[i - 1][j])
            if (dfs(board, curr, i - 1, j))
                return true;
        if (j > 0 && !visited[i][j - 1])
            if (dfs(board, curr, i, j - 1))
                return true;
        if (i < n - 1 && !visited[i + 1][j])
            if (dfs(board, curr, i + 1, j))
                return true;
        if (j < m - 1 && !visited[i][j + 1])
            if (dfs(board, curr, i, j + 1))
                return true;
        curr.pop_back();
        visited[i][j] = false;
        return 0;
    }
    void resetVisited() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = 0;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        target = word;
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> v(n, vector<bool>(m, 0));
        visited = v;
        string curr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                resetVisited();
                curr = "";
                if (dfs(board, curr, i, j))
                    return true;
            }
        }
        return false;
    }
};
```
</details>
</li>
</ul>
