// class Solution {
// public:
//     int f(int i1, int i2, vector<vector<int>> &dp, string s){
//         if (i1 > i2) return 0;
//         if(i1==i2) return 1;
//         if(dp[i1][i2]!=-1) return dp[i1][i2];
//         if(s[i1]==s[i2]) 
//         return dp[i1][i2] = 2+f(i1+1,i2-1,dp,s);
//         else
//         return dp[i1][i2] = 0+max(f(i1+1,i2,dp,s),f(i1,i2-1,dp,s));
    
//     }
//     int longestPalindromeSubseq(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         return f(0,n-1,dp,s);
//     }
// };
//MEMOIZATION GGIVING TLE
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> prev(n, 0), curr(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            curr[i] = 1; // single character is a palindrome
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    curr[j] = 2 + prev[j - 1];
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return prev[n - 1];
    }
};
