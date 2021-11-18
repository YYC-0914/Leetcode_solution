class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 找到最大的idx, 使得nums[idx] <= target
        // 二分查找
        int n = nums.size();
        if (target > nums[n-1]) return n;
        if (target < nums[0]) return 0;
        int l = 0, r = n - 1;
        if (l == r) return 0;
        while (l <= r){
            int mid = l + r + 1 >> 1;
            // cout << "l " << l << " r " << r << " mid " << mid << endl;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }
};
