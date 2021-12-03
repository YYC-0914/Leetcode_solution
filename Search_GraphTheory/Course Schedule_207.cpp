class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 可以使用拓扑排序来处理这道题
        vector<int> h[numCourses + 1];
        vector<int> din(numCourses + 1);
        int cnt = 0;
        queue<int> q;
        // 初始化din和h数组(这里使用h来存储图之间的关系)\
        memset(din, 0, sizeof din);
        for (int i = 0; i < prerequisites.size(); i ++){
            int a = prerequisites[i][1], b = prerequisites[i][0];
            h[a].push_back(b);
            din[b] ++;
        }
        for (int i = 0; i < numCourses; i ++){
            if (!din[i]){
                q.push(i);
                cnt ++;
            }
        }
        while (q.size()){
            int ver = q.front();
            q.pop();
            for (auto k : h[ver]){
                if ((-- din[k]) == 0){
                    q.push(k);
                    cnt ++;
                }
            }
        }
        return cnt == numCourses;
    }
};
