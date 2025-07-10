class Solution {
public:
    int dp[100];
    int f(int i , vector<int> &nums){
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i]+f(i-2, nums);
        int notpick = f(i-1, nums);
        return dp[i] = max(pick, notpick);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return f(nums.size()-1, nums);
    }
};