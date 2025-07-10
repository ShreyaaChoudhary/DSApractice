class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount+1,0);
        dp[0] = 1;
        for(auto coin:coins){
            for(int i = coin ; i<= amount ; i++){
                dp[i] = (long long)dp[i]+dp[i-coin];
            }
        }
        return dp[amount];
    }
};