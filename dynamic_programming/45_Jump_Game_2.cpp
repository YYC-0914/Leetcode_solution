class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_max = 0;
        int n = nums.size();
        int dp[n + 10];
        memset(dp, 0x3f3f3f3f, sizeof dp);
        dp[0] = 0;
        // O(nm) asymptotic complexity
        for (int i = 0; i < n; i++){
            for (int step = 1; step <= nums[i]; step ++){
                if (i + step >= n) continue;
                dp[i + step] = min(dp[i+step], dp[i] + 1);
            }
        }
        return dp[n-1];
    }
};
