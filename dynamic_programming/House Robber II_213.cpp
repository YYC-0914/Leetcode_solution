class Solution {
public:
    int rob(vector<int>& nums) {
        // 可以分类讨论是否选择了第一个房子
        // 先处理掉一些长度比较小的case
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int dp[n+1][2];
        int res1 = 0, res2 = 0;
        // 分类讨论是否选择了第一个房子
        // 没有选择第一间房子
        memset(dp, 0, sizeof dp);
        for (int i = 1; i < n; i ++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        res1 = max(dp[n-1][0], dp[n-1][1]);
        // 选择了第一间房子
        memset(dp, 0, sizeof dp);
        for (int i = 2; i < n; i ++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = dp[i-1][0] + nums[i];
        }
        res2 = dp[n-1][0] + nums[0];
        return max(res1, res2);
    }
};
