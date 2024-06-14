class Solution {
public:
    int target, k;
    
    // Function to get active bits from an integer mask; these represent the numbers included in a combination.
    vector<int> getActiveBits(unsigned int mask) {
        vector<int> activeBits;
        int position = 0;
        while (mask) {
            if (mask & 1) {
                // Position + 1 gives the actual number because bit positions are 0-indexed
                activeBits.push_back(position + 1);
            }
            mask >>= 1;
            position++;
        }
        return activeBits;
    }

    set<int> correctMasks;
    
    // Recursive function to explore all possible combinations using bit manipulation
    void dp(int i, int mask, int sum) {
        // Prune the recursion if the current sum exceeds the target or we have more numbers than needed
        if (sum > target || __builtin_popcount(mask) > k)
            return;
        
        // If current sum equals target and we used exactly k numbers, add the current mask to the set
        if (sum == target && __builtin_popcount(mask) == k) {
            correctMasks.insert(mask);
            return;
        }
        
        // If we've considered all numbers from 1 to 9, return
        if (i == 10)
            return;
        
        // Include the current number in the combination if it does not push the sum over the target
        if (sum + i <= target) {
            dp(i + 1, mask | (1 << (i - 1)), sum + i);
        }
        
        // Exclude the current number and move to the next
        dp(i + 1, mask, sum);
    }

    // Main function to initiate the DFS and collect the results
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;
        this->target = n;
        dp(1, 0, 0);  // Start the DFS with smallest number 1 and initial mask 0 and sum 0
        
        // Prepare the final result using the masks stored in correctMasks set
        vector<vector<int>> activeBitsVectors;
        for (unsigned int mask : correctMasks) {
            activeBitsVectors.pushback(getActiveBits(mask));
        }
        return activeBitsVectors;
    }
};
