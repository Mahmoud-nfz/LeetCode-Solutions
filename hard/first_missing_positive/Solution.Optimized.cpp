class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // In the first loop, replace non-positive integers with (n + 1).
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) 
                nums[i] = n + 1;
        }

        // In the second loop, mark the presence of valid positive integers by changing their signs.
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) 
                nums[abs(nums[i]) - 1] *= -1;
        }

        // In the third loop, find the first positive integer, which represents the smallest missing positive integer.
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) 
                return i + 1;
        }

        // If all positive integers are present, return the next positive integer.
        return n + 1;
    }
};
