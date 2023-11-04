class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Get the number of unique elements in the input array
        int n = nums.size();
        // Initialize a bitset to represent subsets, the i-th bit is active means that we include the i-th element of the array in the current subset
        int bitset = 0; 
        // Initialize a vector to store the resulting subsets
        vector<vector<int>> ans; 

        // Iterate through all possible bitsets
        while (bitset < (1 << n)) { 
            // Create a vector to store the current subset
            vector<int> currSet; 

            for (int i = 0; i < n; i++) {
                // Check if the i-th bit is set in the bitset
                // If so, add the corresponding element to the current subset
                if ((bitset >> i) & 1) 
                    currSet.push_back(nums[i]); 
            }

            // Add the current subset to the result vector
            ans.push_back(currSet); 
            // Increment the bitset to consider the next subset
            bitset++; 
        }

        // Return the vector containing all unique subsets
        return ans; 
    }
};
