class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // 本质上还是得用一个dp[i][j]来存储左侧（含自己）共有多少个连续的1
        if (matrix.size() == 0) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                    if (matrix[i-1][j-1] != '0')
                        dp[i][j] = dp[i][j-1] + 1;
        int res = 0;
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= m; j++){
                int width = dp[i][j];
                int area = width;
                for (int k = i; k >= 1; k --){
                    width = min(width, dp[k][j]);
                    if (! width) break;
                    area = max(area, width * (i-k+1));
                }
                res = max(res, area);
            }
        return res;
    }
};
