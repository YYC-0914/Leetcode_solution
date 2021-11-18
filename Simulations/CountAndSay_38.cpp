class Solution {
public:
    string countAndSay(int n) {
        // It's a straightforward simulation problem, we only need two strings in this case;
        string pre = "1";
        string cur = pre;
        for (int i = 1; i <= n-1; i ++){
            pre = cur;
            // describe the previous string and store the result into cur
            cur = "";
            for (int i = 0; i < pre.size();){
                int cnt = 0;
                char cur_char = pre[i];
                // cout << "pre " << pre << " cur_char " << cur_char << endl;
                int j = i;
                while (pre[j] == cur_char && j < pre.size()){
                    cnt ++;
                    j ++;
                }
                cur += to_string(cnt) + cur_char;
                i = j;
            }
        }
            
        return cur;
    }
};
