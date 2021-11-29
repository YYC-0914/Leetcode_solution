class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // the course must be in a topological order
        // 先建图
        vector<int> ans;
        vector<int> null_ans;
        int n = numCourses + 10;
        int m = prerequisites.size() + 10;
        int h[n], e[m], ne[m], idx = 0;
        int din[n];
        bool st[n];
        memset(st, false, sizeof st);
        memset(din, 0, sizeof din);
        memset(h, -1, sizeof h);
        for (int i = 0; i < prerequisites.size(); i ++){
            int a = prerequisites[i][1], b = prerequisites[i][0];
            // add(a, b);
            e[idx] = b, ne[idx] = h[a], h[a] = idx ++, din[b] ++;
        }
        // topological sort
        queue<int> q;
        for (int i = 0; i < numCourses; i ++){
            if (!din[i]){
                // cout << i << endl;
                q.push(i);
                st[i] = true;
            }
        }
        while (q.size()){
            int ver = q.front();
            // cout << ver << endl;
            ans.push_back(ver);
            q.pop();
            for (int i = h[ver]; ~i; i = ne[i]){
                int j = e[i];
                if (st[j]) continue;
                din[j] --;
                if (!din[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
        if (ans.size() == numCourses) return ans;
        else return null_ans;
    }
};
