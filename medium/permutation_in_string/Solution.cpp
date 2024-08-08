class Solution {
public:
    // Helper function to check if all character counts in the map are zero
    // which indicates a valid permutation match in the current window.
    bool check(map<char, int>& m) {
        bool chk = 1;
        for (auto p : m)
            chk &= p.second == 0;  // AND operation to ensure all counts are zero
        return chk;
    }

    // Main function to determine if s1's permutation is a substring of s2
    bool checkInclusion(string s1, string s2) {
        map<char, int> m; // Map to keep count of characters in s1

        // Populate the map with counts of each character in s1
        for (char c : s1) {
            m[c]++;
        }

        bool found = 0; // Boolean flag to indicate if a permutation has been found
        int i = 0, j = 0; // Pointers for sliding window: i (start), j (end)

        // Iterate through s2 with a sliding window
        while (j < s2.size()) {
            // If current char in s2 reduces the required count in the map
            if (m[s2[j]] > 0) {
                m[s2[j]]--;
                j++;
            } else if (i < j) {
                // If current char is not required or more than required,
                // move the start of the window to the right
                m[s2[i]]++;
                i++;
            } else {
                // If i == j and s2[j] is not in s1, skip this character
                i++;
                j++;
            }
            // Check if the current window is a valid permutation of s1
            found |= check(m);
        }

        // Final check for the last window after exiting the loop
        found |= check(m);

        return found;
    }
};
