class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        // Sort nums1 in non-descending order
        sort(nums1.begin(), nums1.end());
        
        // Store the digits in nums1 in a set for easy searching
        set<int> s1;
        for (auto x : nums1) {
            s1.insert(x);
        }

        // Sort nums2 in non-descending order and search for the smallest digit common to both arrays
        sort(nums2.begin(), nums2.end());
        int ans = -1;
        for (auto x : nums2) {
            if (s1.find(x) != s1.end()) {
                ans = x;
                break;
            }
        }

        // Calculate and return the smallest number that contains at least one digit from each array
        if (nums1[0] == nums2[0]) {
            // If the smallest digit in both arrays is the same, return that digit
            return nums1[0];
        }
        else if (ans != -1) {
            // If there is a digit common to both arrays, return the smallest number that contains it
            return min(ans, min(nums1[0], nums2[0]) * 10 + max(nums1[0], nums2[0]));
        }
        else {
            // If there is no digit common to both arrays, return the smallest number that contains the smallest digit from each array
            return min(nums1[0], nums2[0]) * 10 + max(nums1[0], nums2[0]);
        }
    }
};
