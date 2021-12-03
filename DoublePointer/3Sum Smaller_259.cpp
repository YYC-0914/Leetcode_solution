class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // 本质上还是一个双指针算法
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i ++){
            int k = n - 1;
            for (int j = i + 1; j < n; j ++){
                while (j < k && (nums[i] + nums[j] + nums[k] >= target)) k --;
                if (j == k) break;
                // cout << " i j k " << i << " " << j << " " << k << endl;
                // cout << nums[i] + nums[j] + nums[k] << endl;
                // cout << "________" << endl;
                cnt += k - j;
            }
        }
        return cnt;
    }
};
