class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // putting the word list into an unordered map and use bfs to search for the shortest distance
        unordered_map<string, int> hash;
        unordered_map<string, int> dist;
        for (int i = 0; i < wordList.size(); i ++){
            hash[wordList[i]] = 1;
            dist[wordList[i]] = -1;
        }
        if (!hash.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        dist[beginWord] = 1;
        while (q.size()){
            string ver = q.front();
            // cout << ver << endl;
            q.pop();
            for (int i = 0; i < ver.size(); i ++){
                string tmp = ver;
                for (char ch = 'a'; ch <= 'z'; ch ++){
                    if (ch != ver[i]){
                        tmp[i] = ch;
                        if (hash.count(tmp) && dist[tmp] == -1){
                            if (tmp == endWord) return dist[ver] + 1;
                            q.push(tmp);
                            dist[tmp] = dist[ver] + 1;
                        }
                    }
                }
            }
        }
        return 0;
    }
};
