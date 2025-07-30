class Solution {
public:
    long long calcoin(int i , int target , vector<int> &coins, vector<vector<long long>> &dp){
        if(i==0){
            return (target%coins[i]==0);
        }
        if(dp[i][target]!=-1) return dp[i][target];
        int notpick = 0+calcoin(i-1, target, coins, dp);
        int pick = 0;
        if(coins[i]<=target){
            // pick = 1+calcoin(i-1,target-coins[i],coins,dp); this is wrong bcoz we can choose the same coin multipkel times 
            pick = calcoin(i,target-coins[i],coins,dp);

        }
        return dp[i][target] = pick+notpick;
    }
    int change( int amount,vector<int>& coins) {
        vector<vector<long long>> dp(coins.size(), vector<long long>(amount+1, -1));
        int n = coins.size();
        int ans = calcoin(n-1,amount,coins,dp);
        return ans;
    }
};