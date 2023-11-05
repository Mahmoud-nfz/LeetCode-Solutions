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
