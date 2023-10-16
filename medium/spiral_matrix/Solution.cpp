class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; // Initialize a vector to store the elements in spiral order
        int n = matrix.size(); // Get the number of rows in the matrix
        int m = matrix[0].size(); // Get the number of columns in the matrix
        int remToVisit = n * m; // Initialize the count of remaining elements to visit
        int i = 0, j = 0; // Initialize the current position (i, j) to (0, 0)

        int di[4] = {0, 1, 0, -1}; // Directional increments for rows
        int dj[4] = {1, 0, -1, 0}; // Directional increments for columns

        // Borders are (left to right, then down, then left, then up)
        int borderi[4] = {0, 0, n, n}; // Borders for rows
        int borderj[4] = {0, m, m, -1}; // Borders for columns

        int curr = 0; // Initialize the current direction as right
        ans.push_back(matrix[0][0]); // Add the first element to the result
        remToVisit--;

        // Loop until all elements have been visited
        while (1) {
            int previ = i, prevj = j;

            if (curr % 2 == 0) {
                // Move horizontally while within the current border
                while (j + dj[curr] != borderj[(curr + 1) % 4]) {
                    j += dj[curr];
                    ans.push_back(matrix[i][j]);
                    remToVisit--;
                }
                borderj[(curr + 1) % 4] = j;
            } else if (curr % 2 == 1) {
                // Move vertically while within the current border
                while (i + di[curr] != borderi[(curr + 1) % 4]) {
                    i += di[curr];
                    ans.push_back(matrix[i][j]);
                    remToVisit--;
                }
                borderi[(curr + 1) % 4] = i;
            }

            curr = (curr + 1) % 4; // Update the current direction (right, down, left, up)

            if (!remToVisit)
                break; // If all elements have been visited, exit the loop
        }

        return ans; // Return the elements in spiral order
    }
};
