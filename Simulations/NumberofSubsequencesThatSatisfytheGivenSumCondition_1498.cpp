class Solution {
public:
    static constexpr int mod = 1e9 + 7;
    static constexpr int N = 1e5 + 5;
    int f[N];
    void preprocess(int n){
        f[0] = 1;
        for (int i = 1; i < n; i++){
            f[i] = (long long) f[i-1] * 2 % mod;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        // 本质上是一个双指针算法
        // 将数组从小到大排列
        int sum = 0;
        int n = nums.size();
        preprocess(n+1);
        sort(nums.begin(), nums.end());
        int j = n - 1;
        for (int i = 0; i < n; i ++){
            // 找到符合题意的j
            while (j > i && nums[j] + nums[i] > target) j --;
            if (nums[i] + nums[j] <= target){
                // cout << " i " << i << " j " << j << endl;
                // cout << (2^(j-i)) << endl;
                sum = (sum + f[j-i]) % mod;
            }
        }
        return sum;
    }
};
