class Solution {
public:
    int maxArea(vector<int>& height) {
        // double pointer and greedy algorithm
        int res = 0;
        int l = 0, r = height.size() - 1;
        while (l < r){
            res = max(min(height[l], height[r]) * (r - l), res);
            if (height[l] <= height[r]) l ++;
            else r --;
        }
        return res;
    }
};
