class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // need two dp arrays, one for the maximal product, one for the minimal product
        int n = nums.size();
        vector<int> dp1(n+1), dp2(n+1);
        dp1[0] = dp2[0] = nums[0];
        
        for (int i = 1; i < n; i ++){
            dp1[i] = nums[i];
            dp1[i] = max(dp1[i], max(dp1[i-1] * nums[i], dp2[i-1] * nums[i]));
            dp2[i] = nums[i];
            dp2[i] = min(dp2[i], min(dp1[i-1] * nums[i], dp2[i-1] * nums[i]));
        }
        int res = -0x3f3f3f3f;
        for (int i = 0; i < n; i ++) res = max(res, dp1[i]);
        return res;
    }
};
