class Solution {
public:
    vector<int> dpm; // Dynamic programming array for memoization

    int dp(string& s, int i) {
        // If this state is already computed, return the cached result
        if (dpm[i] != -1) 
            return dpm[i];

        // If we've reached the end of the string, we've found one valid decoding
        if (i == s.size()) 
            return 1;

        // If we are at the second last character of the string, If it's not '0', it can be decoded into a single character
        if (i == s.size() - 1) 
            return s[i] != '0'; 

        // If the current character is '0', it can't be decoded by itself
        if (s[i] == '0')
            return 0;

        // Temporary variable to store the result of this state
        int temp = 0; 

        // Recursively decode the string considering the current character as a single digit
        temp += dp(s, i + 1);

        // Check if the current character and the next character can be combined into a valid two-digit code
        int curr = (s[i] - '0') * 10 + (s[i + 1] - '0');

        // Check if the two digits form a valid code (between 10 and 26)
        if (curr > 9 && curr < 27) 
            // Recursively decode the string with these two digits as a single unit
            temp += dp(s, i + 2); 

        // Store the computed result in the memoization array
        return dpm[i] = temp;
    }

    int numDecodings(string s) {
        // Initialize the DP array with -1 (uncomputed) for each index
        dpm.resize(s.size() + 1, -1); 
        // Start the dynamic programming process from the beginning of the string
        return dp(s, 0); 
    }
};
