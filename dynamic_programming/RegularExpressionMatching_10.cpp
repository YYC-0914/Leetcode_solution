class Solution {
public:
    bool isMatch(string s, string p) {
        // 匿名函数的用法，可以直接使用外部变量，缺点是不能够递归
        auto matches = [&](int i, int j){
            if (i == 0) return false;
            if (p[j-1] == '.') return true;
            return s[i-1] == p[j-1];
        };
        // 定义dp数组
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
        dp[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++){
                if (p[j-1] != '*'){
                    if (matches(i,j)) dp[i][j] = dp[i-1][j-1];
                }
                else{
                    if (matches(i, j-1)){
                        dp[i][j] = dp[i-1][j] || dp[i][j-2];
                        
                    }
                    else dp[i][j] = dp[i][j-2];
                    
                }
            }
        return dp[n][m];
    }
};
