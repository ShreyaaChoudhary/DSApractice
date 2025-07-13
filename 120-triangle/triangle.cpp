class Solution {
public:
    int f(int i, int j , vector<vector<int>> &dp, vector<vector<int>> &tri){
        int n = tri.size();
        int m = tri[0].size();
        if(i==n-1) return tri[i][j];
        if(j>i) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int down = tri[i][j]+f(i+1,j,dp,tri);
        int downright = tri[i][j]+f(i+1,j+1,dp,tri);
        return dp[i][j] = min(down, downright); 

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return f(0,0,dp,triangle);
    }
};