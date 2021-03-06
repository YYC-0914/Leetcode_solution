class Solution {
public:
    bool isMatch(string s, string p) {
        auto match = [&](int i, int j){
            if (i == 0) return false;
            if (p[j-1] == '?') return true;
            return s[i-1] == p[j-1];
        };
        int n = s.size(), m = p.size();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof dp);
        dp[0][0] = true;
        for (int i = 0; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (p[j-1] != '*'){
                    if (match(i, j)){
                        dp[i][j] |= dp[i-1][j-1];
                    }
                }
                else{
                    dp[i][j] |= dp[i][j-1];
                    if (i >= 1) dp[i][j] |= dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};
