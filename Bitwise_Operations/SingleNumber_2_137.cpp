class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // we can actually verify each bits of the ans
        // consider the num of 1, 0 respectively at i-th position
        // consider whether it is divisible by 3
        int ans = 0;
        for (int k = 0; k < 32; k ++){
            int cnt0 = 0, cnt1 = 0;
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] & (1 << k))
                    cnt1 ++;
                else cnt0 ++;
             }
            if (cnt1 % 3 != 0) ans += 1 << k;
        }
        return ans;
    }
};
