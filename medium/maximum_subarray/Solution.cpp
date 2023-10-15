class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize two variables to keep track of the maximum sum so far and the current sum
        int maxSoFar = -1e5; // Initialize to a very small value (negative infinity)
        int curr = 0; // Initialize the current sum to 0

        int n = nums.size(); // Get the size of the input array

        // Iterate through the input array to find the maximum subarray sum
        for (int i = 0; i < n; i++) {
            curr += nums[i]; // Add the current element to the current sum

            // Update maxSoFar to be the maximum of the previous maxSoFar and the current sum
            maxSoFar = max(maxSoFar, curr);

            // If the current sum becomes negative, reset it to 0, as it doesn't contribute to the maximum subarray sum
            if (curr < 0) {
                curr = 0;
            }
        }

        // Return the maximum subarray sum found
        return maxSoFar;
    }
};
