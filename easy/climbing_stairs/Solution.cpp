class Solution {
public:
    // Dynamic programming memoization array
    vector<int> dpm;

    // Recursive function to calculate the distinct ways to climb the stairs
    int dp(int n) {
        if (n <= 1)
            return 1;
        if (n == 2)
            return 2;
        if (dpm[n] != -1)
            return dpm[n];
        // Memoization to avoid redundant calculations
        dpm[n] = dp(n - 1) + dp(n - 2);
        return dpm[n];
    }

    int climbStairs(int n) {
        // Resize the memoization array to accommodate n+2 elements
        dpm.resize(n + 2);
        for (int i = 0; i < n + 2; i++) {
            // Initialize the memoization array with -1
            dpm[i] = -1;
        }
        // Call the dp function to get the distinct ways to climb the stairs
        return dp(n);
    }
};
