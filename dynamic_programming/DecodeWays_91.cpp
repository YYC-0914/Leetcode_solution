class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        if (s[0] == '0') return 0;
        else dp[1] = 1;
        for (int i = 2; i <= n; i++){
            int cur_char = s[i-1];
            int sum = 0;
            // 先特判一下特殊情况
            if (cur_char == '0' && s[i-2] != '1' && s[i-2] != '2') return 0;
            if (cur_char == '0') sum = dp[i-2];
            else{
                if (s[i-2] == '1') sum = dp[i-1] + dp[i-2];
                else if (s[i-2] == '2' && s[i-1] >= '1' && s[i-1] <= '6') sum = dp[i-1] + dp[i-2];
                else sum = dp[i-1];
            }
            dp[i] = sum;
        }
        cout << dp[1] << endl;
        return dp[n];
    }
};
