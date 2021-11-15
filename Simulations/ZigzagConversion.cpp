class Solution {
public:
    string convert(string s, int numRows) {
        // simulation of the process
        // use min(numRows, len(s)) list of strings to store the ultimate answer
        if (numRows == 1) return s;
        vector<string> rows(min(numRows, int(s.size())));
        bool is_down = false;
        int cur_row = 0;
        for (char c : s){
            rows[cur_row] += c;
            if (cur_row == 0 || cur_row == numRows - 1) is_down = ! is_down;
            cur_row += is_down ? 1 : -1;
        }
        string res;
        for (int i = 0; i < rows.size(); i++) res += rows[i];
        return res;
    }
};
