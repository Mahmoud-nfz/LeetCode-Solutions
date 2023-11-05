class Solution {
public:
    string minWindow(string s, string t) {
        if (!t.size())
            return "";

        int i = 0, j = 0;

        // Initialize two vectors to keep track of the characters needed and the original characters in string t
        vector<int> needed(130, 0), original(130, 0);

        // Populate the needed and original vectors with the characters from string t
        for (auto c : t)
            needed[c]++, original[c]++;

        int remToComplete = 0;

        // Calculate the number of unique characters needed
        for (auto x : needed)
            remToComplete += x != 0;

        int ansi = -1, ansj = -1;

        while (j < s.size()) {
            if (original[s[j]]) {
                needed[s[j]]--;
                if (needed[s[j]] == 0)
                    remToComplete--;
            }
            j++;

            while (i < j) {
                if (!original[s[i])
                    i++;
                else if (needed[s[i]] < 0) {
                    needed[s[i]]++;
                    if (needed[s[i]] == 1)
                        remToComplete++;
                    i++;
                } else
                    break;
            }

            // Check if all required characters are found and if the current window is smaller than the previous answer
            if (remToComplete == 0 && ((ansi == -1) || (j - i < ansj - ansi)) {
                ansj = j;
                ansi = i;
            }
        }

        if (ansi == -1)
            return "";
        else
            return s.substr(ansi, ansj - ansi);
    }
};
