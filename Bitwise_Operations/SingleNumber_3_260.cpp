class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // this uses xor operation
        // first find the xor sum of the two number
        long long xor_sum = 0;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) xor_sum ^= nums[i];
        // xor_sum = a ^ b;
        // find the first bit where a and b are different, divide the array into two parts
        // the corresponding xor_sum is a and b respectively
        long long pivot = xor_sum & (-xor_sum);
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++){
            if (nums[i] & pivot) ans1 ^= nums[i];
            else ans2 ^= nums[i];
        }
        ans.push_back(ans1), ans.push_back(ans2);
        return ans;
    }
};
