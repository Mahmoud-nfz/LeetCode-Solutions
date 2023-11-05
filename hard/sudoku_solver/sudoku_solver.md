# Problem : Sudoku Solver

### Difficulty : **Hard**

https://leetcode.com/problems/sudoku-solver/

---

### Tags : **Backtracking**

### Relevant Tutorials :



---

# Statement

<p>Write a program to solve a Sudoku puzzle by filling the empty cells.</p>

<p>A sudoku solution must satisfy <strong>all of the following rules</strong>:</p>

<ol>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each row.</li>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each column.</li>
	<li>Each of the digits <code>1-9</code> must occur exactly once in each of the 9 <code>3x3</code> sub-boxes of the grid.</li>
</ol>

<p>The <code>'.'</code> character indicates empty cells.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png" style="height: 250px; width: 250px;">
<pre><strong>Input:</strong> board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
<strong>Output:</strong> [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
<strong>Explanation:</strong>&nbsp;The input board is shown above and the only valid solution is shown below:

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/31/Sudoku-by-L2G-20050714_solution.svg/250px-Sudoku-by-L2G-20050714_solution.svg.png" style="height: 250px; width: 250px;">
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>board.length == 9</code></li>
	<li><code>board[i].length == 9</code></li>
	<li><code>board[i][j]</code> is a digit or <code>'.'</code>.</li>
	<li>It is <strong>guaranteed</strong> that the input board has only one solution.</li>
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
    // Recursive function to solve the Sudoku puzzle
    void ans(vector<vector<char>>& board, vector<vector<char>>& curr, int i, int j, vector<vector<bool>>& col, vector<vector<bool>>& row, vector<vector<bool>>& mat) {
        while (i < 9 && board[i][j] != '.') {
            // Move to the next cell if the current cell is not empty
            if (j < 8) j++;
            else {
                j = 0;
                i++;
            }
        }
        if (i == 9) {
            // If all cells are filled, store the current solution in 'curr'
            curr = board;
            return;
        }

        for (int k = 1; k <= 9; k++) {
            if (!col[j][k] && !row[i][k] && !mat[3 * (i / 3) + (j / 3)][k]) {
                // Check if it's possible to place digit 'k' at cell (i, j)
                col[j][k] = true;
                row[i][k] = true;
                mat[3 * (i / 3) + (j / 3)][k] = true;
                board[i][j] = (char)('0' + k);
                ans(board, curr, i, j, col, row, mat);
                // If a solution was found exit
                if (curr.size() > 0)
                    break;
                // Else backtrack to try other possibilities
                col[j][k] = false;
                row[i][k] = false;
                mat[3 * (i / 3) + (j / 3)][k] = false;
                board[i][j] = '.';
            }
        }
    }

    // Main function to solve the Sudoku puzzle
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> mat(9, vector<bool>(10, false));
        vector<vector<char>> curr;

        // Initialize col, row, and mat based on the initial state of the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    row[i][x] = true;
                    col[j][x] = true;
                    mat[3 * (i / 3) + (j / 3)][x] = true;
                }
            }
        }

        // Call the recursive function to find the solution
        ans(board, curr, 0, 0, col, row, mat);

        // Copy the solution found in 'curr' back to the 'board'
        board = curr;
        return;
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
    void ans(vector<vector<char>>& board, vector<vector<char>>& curr, int i, int j, vector<vector<bool>>& col, vector<vector<bool>>& row, vector<vector<bool>>& mat) {
        while (i < 9 && board[i][j] != '.') {
            if (j < 8) j++;
            else {
                j = 0;
                i++;
            }
        }
        if (i == 9) {
            curr = board;
            return;
        }
        for (int k = 1; k <= 9; k++) {
            if (!col[j][k] && !row[i][k] && !mat[3 * (i / 3) + (j / 3)][k]) {
                col[j][k] = true;
                row[i][k] = true;
                mat[3 * (i / 3) + (j / 3)][k] = true;
                board[i][j] = (char)('0' + k);
                ans(board, curr, i, j, col, row, mat);
                if (curr.size() > 0)
                    break;
                col[j][k] = false;
                row[i][k] = false;
                mat[3 * (i / 3) + (j / 3)][k] = false;
                board[i][j] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col(9, vector<bool>(10, false));
        vector<vector<bool>> row(9, vector<bool>(10, false));
        vector<vector<bool>> mat(9, vector<bool>(10, false));
        vector<vector<char>> curr;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int x = board[i][j] - '0';
                    row[i][x] = true;
                    col[j][x] = true;
                    mat[3 * (i / 3) + (j / 3)][x] = true;
                }
            }
        }
        ans(board, curr, 0, 0, col, row, mat);
        board = curr;
        return;
    }
};
```
</details>
</li>
</ul>
