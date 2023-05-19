class Solution {
public:
    int rob(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();
        // Create a 2D array to store the dynamic programming results
        int dp[n+3][2];
        
        // Initialize the base case for not robbing the first house
        dp[0][0] = 0;
        // Initialize the base case for robbing the first house
        dp[0][1] = 0;
        
        for (int i = 1; i < nums.size() + 1; i++) {
            // Maximum amount without robbing the current house is the maximum of previous house robbing or not robbing
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            // Maximum amount with robbing the current house is the amount of current house plus the maximum amount without robbing the previous house
            dp[i][1] = nums[i-1] + dp[i-1][0];
        }
        
        // Return the maximum amount that can be robbed from the last house
        return max(dp[n][0], dp[n][1]);
    }
};
