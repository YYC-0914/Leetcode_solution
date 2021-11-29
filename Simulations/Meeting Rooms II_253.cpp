class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // 本质上是一个simulation
        // 用一个minheap存储之前所有的ending time即可
        if (intervals.size() == 1) return 1;
        int cnt = 1;
        priority_queue<int, vector<int>, greater<int>> q;
        sort(intervals.begin(), intervals.end());
        q.push(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i ++){
            int l = intervals[i][0], r = intervals[i][1];
            int min_right = q.top();
            if (l >= min_right){
                q.pop();
            }
            else{
                cnt ++;
            }
            q.push(r);
        }
        return cnt;
    }
};
