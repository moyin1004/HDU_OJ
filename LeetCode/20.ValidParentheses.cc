/// @file    leetcode_20_ValidParentheses.cc
/// @data    2019-01-22 12:47:19

/*
这题考察stack的使用，括号匹配问题。注意不要忽略单个左括号的情况
*/

/*
class Solution {
    public:
        bool isValid(string s) {
            for (auto &elem : s) {
                if (elem == '{' || elem == '(' || elem == '[') {
                    bracket.push(elem);
                }
                else if (!bracket.empty()) {
                    if (bracket.top() == '{' && elem != '}') return false;
                    else if (bracket.top() == '[' && elem != ']') return false;
                    else if (bracket.top() == '(' && elem != ')') return false;
                    bracket.pop();
                }
                else return false;  //防止一个单独的左括号
            }
            if (!bracket.empty()) return false;
            return true;
        }
    private:
        std::stack<char> bracket;
};
*/
