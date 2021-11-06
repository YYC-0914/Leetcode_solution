class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        // greedy algorithm doesn't work
        // have to ues some other alogrithm
        // can be solved using dp and prefix sum
        // dp[i] represents the whether the position i can be reached from 0
        // dp[i] is the OR sum of [dp[i-maxJump], dp[i-minJump]]
        // we can maintain the prefix array while doing the dynamic programming
        int n = s.size();
        bool dp[n + 10];
        int pre[n + 10];
        memset(dp, false, sizeof dp);
        memset(pre, 0, sizeof pre);
        // these are indexed with 1
        dp[1] = true;
        pre[1] = 1;
        for (int i = 1; i < n; i++){
            if (s[i] == '0'){
                if (i - minJump < 0) dp[i+1] = false;
                else{
                    if (pre[i+1 - minJump] - pre[max(1, i + 1 - maxJump) - 1])
                        dp[i+1] = true;
                    else dp[i+1] = false;
                    
                }
            } 
            pre[i+1] = pre[i] + dp[i+1];
        }
        // cout << pre[7+1 - minJump] - pre[min(1, 7 + 1 - maxJump) - 1] << endl;
        // for (int i = 1; i <= n; i++) cout << dp[i] << " ";
        // puts("");
        // for (int i = 1; i <= n; i++) cout << pre[i] << " ";
        return dp[n];
    }
        
        
};
