class NumArray {
public:
    // Dynamic programming array to store cumulative sums
    vector<int> dp;
    
    NumArray(vector<int>& nums) {
        // Resize dp array with size nums.size() + 1 and initialize all elements to 0
        dp.resize(nums.size() + 1, 0);
        for (int i = 1; i < nums.size() + 1; i++) {
            // Calculate cumulative sums and store in dp array
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        // Calculate the sum of elements between indices left and right using the precalculated cumulative sums
        return dp[right + 1] - dp[left];
    }
};
