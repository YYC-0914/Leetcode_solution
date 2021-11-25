class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 简单的动态规划
        int n = triangle.size();
        int dp[n+1][n+1];
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i ++){
            for (int j = 0; j <= i; j ++){
                if (j == 0) dp[i][j] = dp[i-1][j];
                else if (j == i) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);
                dp[i][j] += triangle[i][j];
            }
        }
        int res = 0x3f3f3f3f;
        for (int i = 0; i < n; i ++) res = min(res, dp[n-1][i]);
        return res;
    }
};
