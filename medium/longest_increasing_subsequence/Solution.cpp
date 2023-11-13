// Definition of a Fenwick Tree to handle maximum value queries efficiently
struct FenwickTreeMax {
    vector<int> bit; // Binary Indexed Tree
    // Size of the array
    int n;
    // Minimum possible value
    const int MININT = 0; 

    FenwickTreeMax(int n) {
        this->n = n;
        // Initialize the BIT array with minimum values
        bit.assign(n, MININT); 
    }

    FenwickTreeMax(vector<int> a) : FenwickTreeMax(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    // Get the maximum value in the range [0, r]
    int getMax(int r) {
        int ret = MININT;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = max(ret, bit[r]);
        return ret;
    }

    // Update the BIT with the maximum of the given value and current value at idx
    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = max(bit[idx], val);
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Adjusting input values by adding 10001
        for(int i = 0 ; i < nums.size() ; i ++)
            nums[i] += 10001; 

        int ans = 1, curr = 1 ;
        // Create a Fenwick Tree for efficient maximum value queries
        FenwickTreeMax f(20004); 

        for(int i = 0 ; i < nums.size() ; i ++){
            // Get the maximum length ending just before the current value
            curr = f.getMax(nums[i] - 1); 
            // Update the answer with the maximum length ending at the current value
            ans = max(ans, curr + 1); 
            // Update the Fenwick Tree with the new maximum length
            f.update(nums[i], curr + 1); 
        }

        // Return the maximum length found
        return ans; 
    }
};
