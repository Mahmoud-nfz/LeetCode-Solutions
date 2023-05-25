class Solution {
public:
    // Variable to store the size of the input array
    int n;
    // 2D array to store dynamic programming results
    vector<vector<int>> dpm;
    // Input array
    vector<int> arr;
    // Base value for indexing the dynamic programming array
    int base = 200 * 100 + 3;

    int dp(int i, int diff) {
        // If we have reached the end of the array, check if the difference is zero (indicating equal sum subsets)
        if (i == n)
            return diff == 0;
        
        // If the result for the current state has already been calculated, return it
        if (dpm[i][diff + base] != -1)
            return dpm[i][diff + base];
        
        // Recursively calculate the result by considering including the current element to the first or second set
        dpm[i][diff + base] = (dp(i + 1, diff + arr[i]) || dp(i + 1, diff - arr[i]));
        // Return the result for the current state
        return dpm[i][diff + base];
    }
    
    bool canPartition(vector<int>& nums) {
        // Copy the input array
        arr = nums;
        // Get the size of the input array
        n = nums.size();
        // Resize the dynamic programming array with appropriate dimensions and initialize with -1
        dpm.resize(n + 2, vector<int>(400 * 100 + 7, -1));
        
        // Call the helper function to start the dynamic programming process from the first element with a difference of 0
        return dp(0, 0);
    }
};
