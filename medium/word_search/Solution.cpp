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
