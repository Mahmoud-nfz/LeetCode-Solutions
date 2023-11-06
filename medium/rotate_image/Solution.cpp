class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose the matrix (swap elements across the main diagonal)
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Swap elements at (i, j) and (j, i)
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row to complete the 90-degree clockwise rotation
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                // Swap elements at (i, j) and (i, n - j - 1)
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};
