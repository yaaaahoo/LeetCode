// https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/?envType=study-plan-v2&envId=top-interview-150
/*
给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。

请你计算该表达式。返回一个表示表达式值的整数。

注意：

有效的算符为 '+'、'-'、'*' 和 '/' 。
每个操作数（运算对象）都可以是一个整数或者另一个表达式。
两个整数之间的除法总是 向零截断 。
表达式中不含除零运算。
输入是一个根据逆波兰表示法表示的算术表达式。
答案及所有中间计算结果可以用 32 位 整数表示。
 

示例 1：

输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
示例 2：

输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
示例 3：

输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> st;
            int i = 0;
            while (i < tokens.size()) {
                auto str = tokens[i++];
                if (str != "+" && str != "-" && str != "*" && str != "/") {
                    st.push(std::stoi(str));
                } else {
                    int b = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    if (str == "+") {
                        st.push(a + b);
                    } else if (str == "-") {
                        st.push(a - b);
                    } else if (str == "*") {
                        st.push(a * b);
                    } else if (str == "/") {
                        st.push(a / b);
                    }
                }
            }
    
            return st.top();
        }
    };