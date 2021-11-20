class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        // dp[i] 表示当前从piles[i .. n]中选择，最大可选择的pile的数量的最大值
        // 需要维护一个当前最多可以take多少pile的变量
        // log(10000) = 20
        int n = piles.size();
        int dp[n+1][n+1];
        int sum = 0;
        memset(dp, 0, sizeof dp);
        for (int i = n - 1; i >= 0; i --){
            sum += piles[i];
            for (int j = 1; j <= n; j ++){
                if (i + 2 * j >= n){
                    dp[i][j] = sum;
                }
                else{
                    for (int x = 1; x <= 2 * j; x ++){
                        dp[i][j] = max(dp[i][j], sum - dp[i+x][max(x, j)]);
                    }
                }
            }
        }
        return dp[0][1];
        
    }
};
