class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        // This is a graph theory problem, use bfs to numerate all possible position that start can reach
        int n = arr.size();
        bool st[n+10];
        // using array to simulate a queue
        int q[n+10], hh = 0, tt = -1;
        memset(st, false, sizeof st);
        q[++tt] = start;
        st[start]  = true;
        while (hh <= tt){
            int ver = q[hh++];
            if (arr[ver] == 0) return true;
            int p1 = ver + arr[ver];
            int p2 = ver - arr[ver];
            if (p1 < n && !st[p1]){
                st[p1] = true;
                q[++ tt] = p1;
            }
            if (p2 >= 0 && !st[p2]){
                st[p2] = true;
                q[++ tt] = p2;
            }
        }
        return false;
    }
};
