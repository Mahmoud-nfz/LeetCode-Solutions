# Problem : House Robber II

### Difficulty : **Medium**

https://leetcode.com/problems/house-robber-ii/description/

---

### Tags : **dp**

### Relevant Tutorials :



---

# Statement

<p>You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are <strong>arranged in a circle.</strong> That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and&nbsp;<b>it will automatically contact the police if two adjacent houses were broken into on the same night</b>.</p>

<p>Given an integer array <code>nums</code> representing the amount of money of each house, return <em>the maximum amount of money you can rob tonight <strong>without alerting the police</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [2,3,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,2,3]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>0 &lt;= nums[i] &lt;= 1000</code></li>
</ul>


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
    int n ;
    // make the nums array global by storing it in a
    vector<int> a ;
    // our dp memoization
    vector<vector<vector<int>>> dpm ;
    int dp(int i, int robbed_prev, int robbed_first){
        if(i == n)
            return 0 ;
        // if at the last case we need to check whether the previous case and the first case have been robbed
        // in order to determine whether or not we can rob now
        if(i == n-1)
            return (!robbed_first)*(!robbed_prev)*a[i] ;
        // if result is already memoized return it
        if(dpm[i][robbed_prev][robbed_first] != -1)
            return dpm[i][robbed_prev][robbed_first] ;
        // store answer if we don't rob the current cell
        int ans = dp(i+1,0,robbed_first) ;
        // compare it with answer if we rob current cell when possible
        if(!robbed_prev)
            ans = max(ans,a[i]+dp(i+1,1,robbed_first)) ;
        // return answer
        return dpm[i][robbed_prev][robbed_first] = ans ;
    }
    int rob(vector<int>& nums) {
        a = nums ;
        n = nums.size() ;
        dpm = vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(2,-1))) ;
        return max(dp(1,0,0),a[0]+dp(1,1,1)) ;
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
    int n ;
    vector<int> a ;
    vector<vector<vector<int>>> dpm ;
    int dp(int i, int robbed_prev, int robbed_first){
        if(i == n)
            return 0 ;
        if(i == n-1)
            return (!robbed_first)*(!robbed_prev)*a[i] ;
        if(dpm[i][robbed_prev][robbed_first] != -1)
            return dpm[i][robbed_prev][robbed_first] ;
        int ans = dp(i+1,0,robbed_first) ;
        if(!robbed_prev)
            ans = max(ans,a[i]+dp(i+1,1,robbed_first)) ;
        return dpm[i][robbed_prev][robbed_first] = ans ;
    }
    int rob(vector<int>& nums) {
        a = nums ;
        n = nums.size() ;
        dpm = vector<vector<vector<int>>>(n,vector<vector<int>>(2,vector<int>(2,-1))) ;
        return max(dp(1,0,0),a[0]+dp(1,1,1)) ;
    }
};
```
</details>
</li>
</ul>
