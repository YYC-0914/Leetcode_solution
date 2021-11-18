class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        // 对比stone game 1406, 这题其实有一个更加微妙的定义dp数组的方式
        // dp[i][j] 表示只选择nums[i .. j]时，alice - bob的石子最优方案之差
        // dp[i][j] = max(nums[i-1] - dp[i+1][j], nums[j-1] - dp[i][j-1])
        
        int n = nums.size();
        int dp[n+1];
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++) dp[i] = nums[i-1];
        for (int i = n; i >= 1; i--){
            for (int j = i + 1; j <= n; j++){
                dp[j] = max(nums[i-1] - dp[j], nums[j-1] - dp[j-1]);
            }
        }
        return (dp[n] >= 0);
    }
};
