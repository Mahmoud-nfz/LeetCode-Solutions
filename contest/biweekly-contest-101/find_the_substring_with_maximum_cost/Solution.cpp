class Solution {
public:
    // Define a function to calculate the maximum subarray sum
    int SubarrayWithMaxSum(vector<int>& nums)
    {
        // Initialize currMax and globalMax with first value of nums
        int endIndex, currMax = nums[0];
        int globalMax = nums[0];
 
        // Iterate for all the elements of the array
        for (int i = 1; i < nums.size(); ++i) {
 
            // Update currMax
            currMax = max(nums[i], nums[i] + currMax);
 
            // Check if currMax is greater than globalMax
            if (currMax > globalMax) {
                globalMax = currMax;
                endIndex = i;
            }
        }
        // Set the start index to end index
        int startIndex = endIndex;
        // Return the maximum sum
        return globalMax ;
    }
    
    // Define a function to calculate the maximum cost substring
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        // Define an array to store the cost of each character
        int cost[30] ;
        // Initialize the cost array with the position of each character
        for(int i = 0 ; i < 28 ; i ++){
            cost[i] = i+1 ;
        }
        // Update the cost of each character present in string chars
        for(int i = 0 ; i < chars.size() ; i ++){
            cost[chars[i]-'a'] = vals[i] ;
        }
        // Define a vector to store the cost of each character in the string s
        vector<int> v ;
        // Calculate the cost of each character in the string s using the cost array
        for(auto c : s){
            v.push_back(cost[c-'a']) ;
        }
        // Calculate the maximum subarray sum of the vector v to get the maximum cost substring
        int x = SubarrayWithMaxSum(v) ;
        // Return the maximum cost substring or 0 if all substrings have negative cost
        return max(x,0) ;
    }
};
