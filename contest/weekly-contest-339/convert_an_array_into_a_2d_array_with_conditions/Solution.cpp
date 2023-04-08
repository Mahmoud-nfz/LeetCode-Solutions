/*
    The solution creates a 2D array from the input array satisfying the given conditions.
    It first creates a multiset and a vector to store the distinct integers and their frequencies respectively.
    It then iterates through the multiset until all the integers have been processed.
    In each iteration, it creates a temporary vector to store the distinct integers for a row.
    It adds an integer to the temporary vector only if it hasn't already been added.
    It then decreases the frequency of each integer in the temporary vector and removes it from the multiset if its frequency is 0.
    Finally, it adds the temporary vector to the resulting 2D array.
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        // Create a vector to store the frequency of each integer from the input array
        vector<int> freq(n+3);
        // Create a multiset to store the distinct integers from the input array
        multiset<int> s;
        // Traverse the input array
        for(auto x : nums){  
            s.insert(x);
            freq[x]++;
        }
        // Create a vector of vectors to store the resulting 2D array
        vector<vector<int>> ans;
        // Iterate until all the integers have been processed
        while(!s.empty()){
            int prev = -1;
            // Create a temporary vector to store the distinct integers for a row
            vector<int> temp;
            for(auto x : s){
                // If the integer is already in the temporary vector, skip it
                if(x == prev)
                    continue;
                prev = x;
                temp.push_back(x);
            }
            // Decrease the frequency of the integer and remove it from the multiset if its frequency is 0
            for(auto x : temp){
                freq[x]--;
                if(!freq[x])
                    s.erase(x);
            }
            // Add the temporary vector to the resulting 2D array
            ans.push_back(temp);
        }
        return ans;
    }
};
