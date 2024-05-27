/* 22. Generate Parentheses --> unsuccessfully solved by myself
 * Link: https://leetcode.com/problems/generate-parentheses/description/
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // (...)
        // ()...
        // ()()...
        // ()()()
        // we start with a pair of parentheses

        // think about the problem like this:
        // n dictates how many open parantheses and how many closed parantheses we have
        // 3 => we have 3 open and 3 closed parentheses
        // how many ways can we order the open and close parenthese such that:
            // we cannot have more close paranthese than open parenthese currently on the string
            // we have n open parenthese and n close paranthese

        // maybe we have a counter for number of open and number of closed
        // we always start with an open partanthese
        // at each step, we want to do an open and a close
        
        // SUMMARIZED LOGIC:
            // only add an open paranthese if open < n
            // only add close paranthese if close < open
            // if open paranthese == close paranthese, add open

            // do this problem recursively

        // NEED TO REVIEW RECURSION WITH backtrack(n+1) and backtrack(++n)

        vector<string> answer;

        backtrack(0, 0, n, "", answer);

        return answer;
    }

    // create a recursive function
    void backtrack(int openN, int closeN, int n, string result, vector<string>& answer)
    {
        if (result.length() == 2*n)
        {
            answer.push_back(result);
            return;
        }
        
        if (openN < n)
        { 
            backtrack(openN + 1, closeN, n, result + '(', answer);
        }

        if (closeN < openN)
        {
            backtrack(openN, closeN + 1, n, result + ')', answer);
        }
    }
};
