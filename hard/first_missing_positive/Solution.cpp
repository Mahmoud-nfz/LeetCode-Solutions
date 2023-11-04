class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Create an unordered set to store the present integers.
        unordered_set<int> present; 

        // Iterate through the input array and insert each integer into the set.
        for(auto x: nums){
            present.insert(x);
        }

        // Iterate through positive integers from 1 to (nums.size() + 1).
        for(int i = 1 ; i < nums.size() + 2 ; i++){
            // Check if the current positive integer is not in the set (missing).
            // Return the first missing positive integer found.
            if(present.find(i) == present.end()){
                return i; 
            }
        }
        // If all positive integers are present, return the next positive integer.
        return nums.size() + 1;
    }
};
