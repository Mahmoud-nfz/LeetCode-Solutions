class Solution {
public:
    // Macros for common tasks, enhancing readability.
    #define fr(i,a,b) for(int i = a ; i < b ; i++)
    #define pb push_back
    typedef long long ll;

    // Constants for the hash function.
    const int p = 31;
    const int m = 1e9 + 9;

    // Computes the hash of a string based on each character's position and value.
    long long compute_hash(string const& s) {
        long long hash_value = 0;
        long long p_pow = 1;
        for (char c : s) {
            // Incremental hash computation
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return hash_value;
    }

    // Helper function to determine if a substring is a palindrome.
    bool isPalindrome(string& s, int start, int end) {
        while(start < end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    // Main function to find all palindrome pairs in the given list of words.
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        // Maps to store the forward and reverse hashes of all words.
        map<ll, int> forwardHashes, reverseHashes;

        // Populate the hash maps.
        fr(i,0,n){
            forwardHashes[compute_hash(words[i])] = i;   
            reverse(words[i].begin(), words[i].end());
            reverseHashes[compute_hash(words[i])] = i;
        }

        vector<vector<int>> pairs;
        fr(i,0,n){
            long long hash_value = 0;
            long long p_pow = 1;
            // Check potential pairs by examining each prefix of the current word.
            fr(j,0,words[i].size()){
                if(forwardHashes.count(hash_value) && isPalindrome(words[i], j, words[i].size()-1)){
                    if(forwardHashes[hash_value] != i)
                        pairs.pb({forwardHashes[hash_value], i});
                }
                char c = words[i][j];
                hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
                p_pow = (p_pow * p) % m;
            }
            // Check if the whole word can form a pair with an empty string or similar case.
            if(forwardHashes.count(hash_value)){
                if(forwardHashes[hash_value] != i)
                    pairs.pb({forwardHashes[hash_value], i});
            }

            // Repeat the check for reversed strings.
            reverse(words[i].begin(), words[i].end());
            hash_value = 0;
            p_pow = 1;
            fr(j,0,words[i].size()){
                if(reverseHashes.count(hash_value) && isPalindrome(words[i], j, words[i].size()-1)){
                    if(reverseHashes[hash_value] != i)
                        pairs.pb({i, reverseHashes[hash_value]});
                }
                char c = words[i][j];
                hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
                p_pow = (p_pow * p) % m;
            }
        }

        return pairs;
    }
};
