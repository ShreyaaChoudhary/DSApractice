class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
        return 0;
        int n = s.size();
        vector<int> dp(n+1,0);
        dp[0] = 1;//0  ways for empty string
        dp[1] = 1;//1 way for string containing a single character
        for(int i = 2; i<=n; i++){
            //1 digit decode
            if(s[i-1]<='9' && s[i-1]>='1'){
                dp[i] = dp[i]+dp[i-1]; //because the numberof wyas to decode include all the ways utpo i-1 and the single digit itself
            }
            //2 digit decode
            string twodig = s.substr(i-2,2);
            if(twodig<="26" && twodig>="10"){
                dp[i] = dp[i]+dp[i-2]; //i-2 gives the number of ways to decode up to the point before the 2digit number 
            }
        }
        return dp[n];
    }
};