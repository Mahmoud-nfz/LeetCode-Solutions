# Problem : Combination Sum IV

### Difficulty : **Medium**

https://leetcode.com/problems/combination-sum-iv/

---

### Tags : **DP**

### Relevant Tutorials :



---

# Statement



---

# Solution 

Solutions Author : https://github.com/Mahmoud-nfz

## C++ Solution

<ul>
<li>

<details>
    <summary>Explained Solution</summary>

```cpp
class Solution {
public:
    // dp function
    // our dp is done on the two variables {target,i}
    // target refers to the current target that we need to sum up to
    // i refers to the position that we reached so far in the nums vector
    // we store in the matrix dpm the answer to each of the queries :
    // "What are the possible combinations that add up to {target} if we start at position {i} ?"

    int dp(vector<vector<int>>& dpm,vector<int>& nums, int target, int i){
        // we know that nums only contains positive values, so it's always impossible to find a combination that sums to a negative target
        if(target < 0 )
            return 0 ;
        // if we reached the end of the array then :
        //  - either we already found our desired combinations (target == 0) so the answer is 1 since the only sequence present summing to 0 is []
        //  - we still have some leftover, but since we reached the end we can't fullfill that so the answer is 0
        if(i == nums.size())
            return target == 0 ;
        // if we already have the desired value stored then we just return it, -1 represents a cell that we haven't filled yet
        if(dpm[target][i] != -1)
            return dpm[target][i] ;
        // our answer is the number of sequences that don't use the element at position i + the number of sequences that use it
        // here we decide not to use nums[i] and find the number of sequences that don't use it
        int ans = dp(dpm,nums,target,i+1) ;
        // if nums[i] < target then we can use it once and check if we can reach target by calling dp(..,target-nums[i],0)
        // meaning we try to reach target starting from THE START OF THE VECTOR NUMS (position 0)
        if(nums[i] <= target)
            curr += dp(dpm,nums,target-nums[i],0) ;
        // we store the calculated value in dpm before returning it
        dpm[target][i] = curr ;
        return dpm[target][i] ;
    }
    // Our Complexity is O(targets*(nums.size())) 
    // since that is the size of our dp search and we are using memoization


    // driver function
    int combinationSum4(vector<int>& nums, int target) {
        // initialize the dp matrix of size (target+1)*(nums.size()) (which we will name dpm) to -1
        vector<vector<int>> dpm(target+1, vector<int> (nums.size(),-1));
        // then we call the dp function
        return dp(dpm,nums,target,0) ;
    }
};
```
</details>
</li>

<li>
<details>
    <summary>Raw Solution</summary>

```cpp
class Solution {
public:
    int dp(vector<vector<int>>& dpm,vector<int>& nums, int target, int i){
        if(target < 0 )
            return 0 ;
        if(i == nums.size())
            return target == 0 ;
        if(dpm[target][i] != -1)
            return dpm[target][i] ;
        int ans = dp(dpm,nums,target,i+1) ;
        if(nums[i] <= target)
            curr += dp(dpm,nums,target-nums[i],0) ;
        dpm[target][i] = curr ;
        return dpm[target][i] ;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dpm(target+1, vector<int> (nums.size(),-1));
        return dp(dpm,nums,target,0) ;
    }
};
```
</details>
</li>
</ul>
