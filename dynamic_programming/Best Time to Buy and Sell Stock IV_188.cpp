class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (! n) return 0;
        int dp[n+1][k+1][2];
        memset(dp, -0x3f, sizeof dp);
        for (int i = 0; i <= n; i ++) dp[i][0][0] = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= k; j ++){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i-1]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i-1]);
            }
        int res = 0;
        for (int i = 0; i <= k; i ++) res = max(res, dp[n][i][0]);
        return res;
    }
};
