class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        // Pair of value, list index, and index within the list
        // This will keep track of the biggest element of each array that is present in our chosen set
        // pair<element,pair<array number, index in array> 
        set<pair<int, pair<int, int>>> curr;

        // Initialize the set with the first element from each list
        for (int i = 0; i < n; i++) {
            curr.insert(make_pair(nums[i][0], make_pair(i, 0)));
        }

        int shortest = 1e9;
        int l = 1e6, r = -1e6;

        // Continue updating the range until the end of any list is reached
        while (true) {
            int x = curr.begin()->first, y = curr.rbegin()->first;

            // Update the range if the current range is smaller
            if (y - x < shortest) {
                shortest = y - x;
                r = y;
                l = x;
            }

            int i = curr.begin()->second.first, j = curr.begin()->second.second;
            j++;

            // Move to the next element in the list with the smallest value
            if (j < nums[i].size()) {
                curr.erase(curr.begin());
                curr.insert(make_pair(nums[i][j], make_pair(i, j)));
            } else {
                // Break the loop if the end of any list is reached
                break;
            }
        }

        // Check the range one more time before returning
        int x = curr.begin()->first, y = curr.rbegin()->first;
        if (y - x < shortest) {
            shortest = y - x;
            r = y;
            l = x;
        }

        // Return the smallest range as a vector
        vector<int> ans;
        ans.push_back(l);
        ans.push_back(r);
        return ans;
    }
};
