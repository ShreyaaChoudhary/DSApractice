class Solution {
public:
    // bool findsub(int i, int target , vector<vector<int>> &dp, vector<int> &nums){
    //     if(target==0) return true;
    //     if(i==0) return target==nums[i];
    //     int notpick = findsub(i-1, target, dp, nums); 
    //     int pick = false;
    //     if(nums[i]<=target){
    //         pick = findsub(i-1,target-nums[i], dp, nums);
    //     }
    //     return dp[i][target] = notpick||pick;
    // }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        if(total%2!=0) return false;
        int target = total/2;
        vector<bool> dp(target+1,false);
        dp[0] = true;
        for(auto n:nums){
            for(int i = target; i>=n; i--){
                if(dp[i]) continue;
                if(dp[i-n]) dp[i] = true;
                if(dp[target]) return true;
            }
        }
        return false;
        // int total = accumulate(nums.begin(), nums.end(), 0);
        // if(total%2!=0) return false;
        // int target = total/2;
        // vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        // return findsub(nums.size()-1,target,dp,nums);
    }
};