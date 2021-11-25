class Solution {
public:
    int maxProfit(vector<int>& prices) {
                int n = prices.size();
        int dp[n+1][2];
        memset(dp, -0x3f, sizeof dp);
        dp[0][0] = 0;
        for (int i = 1; i <= n; i ++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1]);
        }
        int res = 0;
        for (int i = 0; i <= n; i ++) res = max(res, dp[i][0]);
        return res;
    }
};
