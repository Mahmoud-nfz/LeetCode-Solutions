# Problem : Spiral Matrix

### Difficulty : **Medium**

https://leetcode.com/problems/spiral-matrix/

---

### Tags : **matrices, traversals**

### Relevant Tutorials :



---

# Statement

<p>Given an <code>m x n</code> <code>matrix</code>, return <em>all elements of the</em> <code>matrix</code> <em>in spiral order</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg" style="width: 242px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[1,2,3],[4,5,6],[7,8,9]]
<strong>Output:</strong> [1,2,3,6,9,8,7,4,5]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg" style="width: 322px; height: 242px;">
<pre><strong>Input:</strong> matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
<strong>Output:</strong> [1,2,3,4,8,12,11,10,9,5,6,7]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == matrix.length</code></li>
	<li><code>n == matrix[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 10</code></li>
	<li><code>-100 &lt;= matrix[i][j] &lt;= 100</code></li>
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

```
</details>
</li>

<li>
<details>
    <summary>Raw Solution</summary>

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; 
        int n = matrix.size(); 
        int m = matrix[0].size(); 
        int remToVisit = n * m; 
        int i = 0, j = 0; 
        int di[4] = {0, 1, 0, -1}; 
        int dj[4] = {1, 0, -1, 0}; 
        int borderi[4] = {0, 0, n, n}; 
        int borderj[4] = {0, m, m, -1}; 
        int curr = 0; 
        ans.push_back(matrix[0][0]); 
        remToVisit--;
        while (1) {
            int previ = i, prevj = j;
            if (curr % 2 == 0) {
                while (j + dj[curr] != borderj[(curr + 1) % 4]) {
                    j += dj[curr];
                    ans.push_back(matrix[i][j]);
                    remToVisit--;
                }
                borderj[(curr + 1) % 4] = j;
            } else if (curr % 2 == 1) {
                while (i + di[curr] != borderi[(curr + 1) % 4]) {
                    i += di[curr];
                    ans.push_back(matrix[i][j]);
                    remToVisit--;
                }
                borderi[(curr + 1) % 4] = i;
            }
            curr = (curr + 1) % 4; 
            if (!remToVisit)
                break; 
        }
        return ans; 
    }
};
```
</details>
</li>
</ul>
