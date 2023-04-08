/*
    The code uses a brute force approach to find all possible substrings of s, and then checks if each substring is balanced by counting the number of zeroes and ones.
    If a substring is balanced, the code updates the maximum length of balanced substrings seen so far.
    Finally, the code returns the maximum length of balanced substrings.

    Note that this solution has a time complexity of O(n^3), where n is the length of the input string s.
    Therefore, for large input sizes, this solution may take a long time to run.
    There are more efficient algorithms to solve this problem that have a lower time complexity.
*/

class Solution {
public:
    // Define a function to find the longest balanced substring in the binary string s
    int findTheLongestBalancedSubstring(string s) {
        // Initialize the maximum length of the balanced substring to be zero
        int ans = 0 ;
        // Loop through all possible pairs of starting and ending indices of substrings in s
        for(int i = 0 ; i < s.size() ; i ++){
            for(int j = i+1 ; j < s.size() ; j += 2){
                // Check if the substring is balanced by counting the number of zeroes and ones
                int x = 1 ;
                for(int k = i ; k <= (j+i)/2 ; k ++){
                    if(s[k] != '0')
                        x = 0 ;
                }
                for(int k = (j+i)/2 + 1 ; k <= j ; k ++){
                    if(s[k] != '1')
                        x = 0 ;
                }
                // If the substring is balanced, update the maximum length
                if(x)
                    ans = max(ans,j-i+1) ;
            }
        }
        // Return the maximum length of the balanced substring
        return ans ;
    }
};
