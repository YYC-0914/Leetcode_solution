class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i] 表示在i这个位置卖掉的最大收益
        // min_val用来维护之前的所有天数中的最小值
        int n = prices.size();
        if (n == 1) return 0;
        int min_val = prices[0];
        int res = 0;
        for (int i = 1; i < n; i++){
            int cur_profit = max(0, prices[i] - min_val);
            res = max(res, cur_profit);
            min_val = min(min_val, prices[i]);
        }
        return res;
    }
};
