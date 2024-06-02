class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // This vector will store the indices of all zeros in the array
        vector<int> zeros;
        // This will keep track of the index in the zeros vector
        int zidx = 0;
        
        // Loop through the array and record the indices of zeros
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0)
                zeros.push_back(i);
        }

        // Count of zeros that have been flipped
        int zerosChanged = 0;
        // Two pointers defining the current window of 1s potentially including some flipped 0s
        int l = 0, r = 0;
        // This will store the maximum number of consecutive ones found
        int ans = 0;
        
        // Main loop through the array
        while(r < nums.size()) {
            // Update the answer each iteration to ensure it includes cases where the loop ends without another update
            ans = max(ans, r - l);
            
            if(nums[r] == 1) {
                // If current number is 1, just expand the right end of the window
                r++;
            } else { // If current number is 0
                if(zerosChanged < k) {
                    // If we have not exhausted our quota of flips
                    r++; // Expand the window
                    zerosChanged++; // Use up one of our allowed flips
                } else { 
                    // If we have exhausted our flips
                    r++; // Still expand the window
                    // Move the left end of the window to one past the oldest zero in the current window
                    l = zeros[zidx] + 1;
                    // Move to the next zero in the list
                    zidx++; 
                }
            }
        }

        // Final check to update the answer in case the longest sequence is at the end of the array
        ans = max(ans, r - l);

        // Return the maximum length found
        return ans;
    }
};
