class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> ans(n, 0);

        // Step 1: Calculate the highest bar to the left of each position
        int highestSoFar = 0;
        for (int i = 0; i < n; i++) {
            if (height[i] < highestSoFar) {
                ans[i] = highestSoFar;
            } else {
                ans[i] = height[i];
                highestSoFar = height[i];
            }
        }

        // Step 2: Calculate the highest bar to the right of each position
        highestSoFar = 0;
        for (int i = n - 1; i >= 0; i--) {
            highestSoFar = max(height[i], highestSoFar);
            ans[i] = min(ans[i], highestSoFar);
        }

        // Step 3: Calculate the amount of trapped water
        int result = 0;
        for (int i = 0; i < n; i++) {
            result += ans[i] - height[i];
        }

        return result;
    }
};
