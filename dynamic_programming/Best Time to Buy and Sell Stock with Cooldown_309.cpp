class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        int dp[n+1][3];
        // dp[i][0] 表示考虑到第i天，手上持有股票的最大收益
        // dp[i][1] 表示考虑到第i天，手上股票刚抛售一天时的最大收益
        // dp[i][2] 表示考虑到第i天，手上股票已经不在冷却期的最大收益
        memset(dp, -0x3f, sizeof dp);
        dp[0][2] = 0;
        for (int i = 1; i <= n; i ++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2] - prices[i-1]);
            dp[i][1] = dp[i-1][0] + prices[i-1];
            dp[i][2] = max(dp[i-1][1], dp[i-1][2]);
        }
        return max(dp[n][1], dp[n][2]);
    }
    
};
