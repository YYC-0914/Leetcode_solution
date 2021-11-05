class Solution {
public:
    int trap(vector<int>& height) {
        // dp1[i] records the highest wall to ith position's left
        // dp2[i] records the highest wall to ith position's right
        int n = height.size();
        int ans = 0;
        int dp1[n + 10], dp2[n + 10];
        memset(dp1, 0, sizeof dp1);
        memset(dp2, 0, sizeof dp2);
        for (int i = 1; i < n; i++)
            dp1[i] = max(height[i-1], dp1[i-1]);
        for (int i = n-2; i >= 0; i--)
            dp2[i] = max(height[i+1], dp2[i+1]);
        for (int i = 0; i < n; i++){
                int dif = max(0, min(dp1[i], dp2[i]) - height[i]);
                ans += dif;
            }
        return ans;
    }
};
