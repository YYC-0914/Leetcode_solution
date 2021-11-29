class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return true;
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); i ++){
            int cur_l = intervals[i][0], pre_r = intervals[i-1][1];
            if (cur_l < pre_r) return false;
        }
        return true;
    }
};
