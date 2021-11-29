class Solution {
public:
    int find(vector<int> &p, int ver){
        if (p[ver] != ver) p[ver] = find(p, p[ver]);
        return p[ver];
    }
    
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        // 本质上使用并查集算法解决这个问题
        vector<int> p(m*n + 10, -1);
        vector<int> ans;
        int dx[4] = {0, 0, -1, 1}, dy[4] = {1,-1,0,0};
        int cnt = 0;
        for (int i = 0; i < positions.size(); i ++){
            int x = positions[i][0], y = positions[i][1];
            if (p[x * n + y] != -1){
                ans.push_back(cnt);
                continue;
            }
            int father = -1;
            for (int i = 0; i < 4; i ++){
                int a = x + dx[i], b = y + dy[i];
                if (a < 0 || a >= m || b < 0 || b >= n) continue;
                if (p[a*n +b] == -1) continue;
                int cur = a * n +b;
                if (father == -1){
                    father = find(p, cur);
                    p[x *n + y] = father;
                }
                else{
                    int new_father = find(p, cur);
                    if (new_father != father){
                        cnt --;
                        p[new_father] = father;
                    }
                }
            }
            if (father == -1){
                p[x * n + y] = x * n + y;
                cnt ++;
            }
            // cout << "father " << father << endl;
            ans.push_back(cnt);
        }
        return ans;
    }
};
