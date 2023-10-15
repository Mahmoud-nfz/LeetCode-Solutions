class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Create sets to store the indices of rows and columns with zeros
        set<int> cols, rows;

        // Traverse the matrix to identify zero elements and their positions
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (!matrix[i][j]) {
                    // Store the indices of rows and columns with zeros in the sets
                    cols.insert(j);
                    rows.insert(i);
                }
            }
        }

        // Traverse the matrix again to set zeros in the appropriate rows and columns
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                // If the current row index or column index is in the respective sets, set the element to 0
                if (cols.find(j) != cols.end() || rows.find(i) != rows.end()) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
