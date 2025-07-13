class Solution {
public:
    int f(int i,vector<int> &dp){
        if(i<=2) return i;
        if(dp[i]!=0) return dp[i];
        return dp[i] = f(i-1,dp)+f(i-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        return f(n,dp);
    }
};