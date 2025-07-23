class Solution {
public:
    int calcoin(int i , int target , vector<int> &coins, vector<vector<int>> &dp){
        if(i==0){
            if(target%coins[i]==0) return target/coins[i];
            else return 1e9;
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notpick = 0+calcoin(i-1, target, coins, dp);
        int pick = 1e9;
        if(coins[i]<=target){
            // pick = 1+calcoin(i-1,target-coins[i],coins,dp); this is wrong bcoz we can choose the same coin multipkel times 
            pick = 1+calcoin(i,target-coins[i],coins,dp);

        }
        return dp[i][target] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int n = coins.size();
        int ans = calcoin(n-1,amount,coins,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};