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