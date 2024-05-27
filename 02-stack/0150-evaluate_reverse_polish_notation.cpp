/* 150. Evaluate Reverse Polish Notation
 * Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
 */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        // INSTEAD OF KEEPING NUMS AS STRINGS, MAYBE MAKE THEM INTS?

        stack<string> num_stack;

        // loop through vector
        // if you hit an operation
        // then you need to pop two numbers from num_stack and then evaluate
        // then push evaluated thing on the num_stack again

        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/")
            {
                int b = stoi(num_stack.top()); num_stack.pop();
                int a = stoi(num_stack.top()); num_stack.pop();
                int c;

                if (tokens[i] == "+")
                    c = a + b;
                else if (tokens[i] == "-")
                    c = a - b;
                else if (tokens[i] == "*")
                    c = a * b;
                else if (tokens[i] == "/")
                    c = a / b;

                num_stack.push(to_string(c));
            }
            else
            {
                num_stack.push(tokens[i]);
            }

        }

        return stoi(num_stack.top());
        
    }
};
