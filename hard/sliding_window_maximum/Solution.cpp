class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> window;

        // Initialize the window with the first 'k' elements
        for (int i = 0; i < k; i++) {
            window.insert(nums[i]);
        }

        // Add the maximum of the initial window to the result
        ans.push_back(*window.rbegin());

        int i = 0, j = k;

        // Slide the window from left to right
        while (j < nums.size()) {
            // Remove the element that goes out of the window from the multiset
            window.erase(window.find(nums[i]));

            // Insert the new element that comes into the window
            window.insert(nums[j]);

            // Add the maximum of the current window to the result
            ans.push_back(*window.rbegin());

            i++;
            j++;
        }

        return ans;
    }
};
