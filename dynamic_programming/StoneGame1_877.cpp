class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        // // dp[i][j]表示为剩下的piles[i .. j]， 当前的玩家最多可以拿多少石子
        // // dp[i][i] = plies[i];
        // int n = piles.size();
        // int dp[n+1][n+1], sum[n+1];
        // memset(dp, 0, sizeof dp);
        // memset(sum, 0, sizeof sum);
        // for (int i = 1; i <= n; i ++) sum[i] = piles[i-1] + sum[i-1];
        // for (int len = 1; len <= n; len ++){
        //     for (int i = 1; i <= n; i ++){
        //         int j = i + len - 1;
        //         if (j > n) continue;
        //         if (i == j) dp[i][j] = piles[i-1];
        //         else{
        //             dp[i][j] = max(sum[j] - sum[i-1] - dp[i+1][j], sum[j] - sum[i-1] - dp[i][j-1]);
        //         }
        //     }
        // }
        // // cout << dp[1][4] << endl;
        // if (dp[1][n] * 2 > sum[n]) return true;
        // else return false;
        return true;
    }
};
