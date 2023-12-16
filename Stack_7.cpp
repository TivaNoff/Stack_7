#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            }
            else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                }
                else {
                    maxLength = max(maxLength, i - stk.top());
                }
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;

    cout << solution.longestValidParentheses("(()") << endl;
    cout << solution.longestValidParentheses(")()())") << endl;
    cout << solution.longestValidParentheses("") << endl; 

    return 0;
}
