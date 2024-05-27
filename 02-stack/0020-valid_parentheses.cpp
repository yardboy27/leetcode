/* 20. Valid Parentheses
 * Link: https://leetcode.com/problems/valid-parentheses/description/
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;

        if (s.size() == 1)
            return false;

        for (char c : s)
        {
            chars.push(c);

            if (chars.top() == ')')
            {
                chars.pop();
                if (chars.size() == 0 || chars.top() != '(') return false;
                chars.pop();
            }
            else if (chars.top() == ']')
            {
                chars.pop();
                if (chars.size() == 0 || chars.top() != '[') return false;
                chars.pop();
            }
            else if (chars.top() == '}' )
            {
                chars.pop();
                if (chars.size() == 0 || chars.top() != '{') return false;
                chars.pop();
            }
        }

        if (chars.size())
            return false;

        return true;
    }
};
