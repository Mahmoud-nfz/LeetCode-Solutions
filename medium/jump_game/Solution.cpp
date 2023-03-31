/*

Solution: We can use dynamic programming to solve this problem.
Let's define a boolean array called possible where possible[i] represents whether we can jump from the ith index to the last index.
We start with possible[n-1] = true since we are already at the last index.
Then, we move backwards in the array from n-2 to 0, and for each index i, we determine whether we can jump to the last index from that index.

To determine if we can jump from index i, we look at all the indices we can jump to from index i, and check if any of those indices are possible.
We can keep track of the possible indices using a suffix sum. suffix_sum[i] represents the number of indices we can jump to from i that are possible.
We can compute this by summing possible[i+1] to possible[n-1], and adding one for each possible[i+1] (since we can jump from i to i+1 and i+1 is possible).

Once we have the suffix sum, we can determine whether we can jump from i by checking if suffix_sum[i+1] - suffix_sum[min(n,i+nums[i]+1)] is greater than 0. If this is true, it means we can jump to a possible index from i, so we set possible[i] to true. We then update suffix_sum[i] to be the sum of suffix_sum[i+1] and possible[i].

Finally, we return whether we can jump from index 0, i.e., whether possible[0] is true.

Time Complexity: O(n), where n is the length of the input array.
Space Complexity: O(n), for the two arrays possible and suffix_sum.

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> possible(n,0), suffix_sum (n+1,0) ;
        
        // Base case
        possible[n-1] = 1 ;
        suffix_sum[n-1] = 1 ;
        
        // Loop from n-2 to 0
        for(int i = n-2 ; i >= 0 ; i --){
            // Determine whether we can jump to the last index from index i
            possible[i] = suffix_sum[i+1] - suffix_sum[min(n,i+nums[i]+1)] > 0 ;
            
            // Update suffix_sum[i] using possible[i]
            suffix_sum[i] = suffix_sum[i+1] + possible[i] ;
        }
        
        // Return whether we can jump from index 0 to the last index
        return possible[0] == 1 ;
    }
};
