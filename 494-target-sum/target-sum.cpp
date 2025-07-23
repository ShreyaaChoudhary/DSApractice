class Solution {
public:
    int dpp(vector<int> &nums, int target, int currsum, int i, vector<vector<int>> &dp,int offset){
        if (i == 0) {
            int cnt = 0;
            if (currsum + nums[0] == target) cnt++;
            if (currsum - nums[0] == target) cnt++;
            return cnt;
        }
        if(dp[i][currsum+offset]!=-1) return dp[i][currsum+offset];
        int pos = dpp(nums,target, currsum + (+nums[i]), i-1, dp,offset);
        int neg = dpp(nums,target,currsum +(-nums[i]), i-1, dp,offset);
        return dp[i][currsum+offset] = pos+neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > total) return 0;
        vector<vector<int>> dp(nums.size(), vector<int>(2*total+1,-1));
        int n = nums.size();
        return dpp(nums,target,0,n-1, dp,total);
    }
};