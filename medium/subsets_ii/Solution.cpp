class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Get the size of the input array.
        int n = nums.size();           
        // Initialize a bitset to 0 to represent subsets.
        int bitset = 0;                
        // Use a set to store unique subsets.
        set<vector<int>> ans;

        // Loop through all possible bitsets (subsets).
        while (bitset < (1 << n)) {
            // Create a vector to store the current subset.
            vector<int> currSet;
            for (int i = 0; i < n; i++) {
                // Check if the i-th bit of the bitset is set (1).
                // If so, add the corresponding element to the current subset.
                if ((bitset >> i) & 1) {
                    currSet.push_back(nums[i]);  
                }
            }
            // Sort the current subset elements in order to check if the subset is already present in a different order.
            sort(currSet.begin(), currSet.end()); 
            // Insert the sorted subset into the set.
            ans.insert(currSet);
            // Move to the next bitset.
            bitset++;
        }

        // Convert the result to a vector of vectors
        vector<vector<int>> result;
        for (const vector<int>& vec : ans) {
            result.push_back(vec);
        }
        return result;
    }
};
