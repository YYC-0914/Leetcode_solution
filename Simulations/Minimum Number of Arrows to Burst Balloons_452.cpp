class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 本质上是一个贪心加simulation，算法的正确性还是比较好说明的
        if (points.size() == 1) return 1;
        sort(points.begin(), points.end());
        int cnt = 1;
        int max_l = points[0][0], min_r = points[0][1];
        for (int i = 1; i < points.size(); i ++){
            int l = points[i][0], r = points[i][1];
            // cout << "l " << l << " r " << r << endl;
            // cout << "max_l " << max_l << " min_r " << min_r << endl;
            if (l > min_r){
                cnt ++;
                max_l = l, min_r = r;
            }
            else{
                max_l = max(max_l, l);
                min_r = min(min_r, r);
            }
        }
        return cnt;
    }
};
