class Solution {
public:
    int longestValidParentheses(string s) {
        // 可以直接使用栈来解决这样的括号匹配问题
        // 每次读入一个括号，如果是左括号就入栈，如果是右括号就弹出一个和它匹配
        // 如果栈为空的时候就将当前的最大值变为0
        stack<int> stk;
        int ans = 0;
        stk.push(-1);
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                stk.push(i);
            }
            else{
                stk.pop();
                if (! stk.size()){
                    stk.push(i);
                }
                else ans = max(ans, i - stk.top());
            }
        }
            return ans;
        }
};
