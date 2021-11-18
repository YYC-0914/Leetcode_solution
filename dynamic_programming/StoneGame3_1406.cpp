class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        // dp[i] represents the maximal value that a forehand player can get from the stone sets {i, i+1, ... n}
        // dp[i] = max(sum[i..n] - dp[i+1], sum[i..n] - dp[i+2], sum[i..n] - dp[i+3])
        // 所以先做一遍前缀和
        int n = stoneValue.size();
        int dp[n+10], sum[n+1];
        memset(dp, 0, sizeof dp);
        memset(sum, 0, sizeof sum);
        dp[n] = stoneValue[n-1];
        for (int i = 1; i <= n; i ++) sum[i] = sum[i-1] + stoneValue[i - 1];
        for (int i = n-1; i >= 1; i --){
            int maxval = sum[n] - sum[i-1] - dp[i+1];
            maxval = max(maxval, sum[n] - sum[i-1] - dp[i+2]);
            maxval = max(maxval, sum[n] - sum[i-1] - dp[i+3]);
            dp[i] = maxval;
        }
        if (2*dp[1] > sum[n]) return "Alice";
        else if (2*dp[1] < sum[n]) return "Bob";
        else return "Tie";
    }
};
