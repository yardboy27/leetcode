/* 739. Daily Temperatures
 * Link: https://leetcode.com/problems/daily-temperatures/description/
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // n^2 solution --> 2 for loops, comparing temperatures[i] to temperatures[j], returning a count when temp[i] < temp[j]

        // **as soon as we find a day that has a temp that is greater than the day we are on, we no longer care about it**
        // we can keep adding to the stack, and when we hit a hotter temp than the stack on top, then we keep popping
        // until we hit a temp that is not lower than it

        vector<int> answer (temperatures.size(), 0);

        // have a stack that has a pair: temperature, index
        stack<pair<int, int>> temp_stack;

        for (int i = 0; i < temperatures.size(); ++i)
        {

            while (!temp_stack.empty() && temp_stack.top().first < temperatures[i])
            {
                int answer_index = temp_stack.top().second;

                answer[answer_index] = i - answer_index;

                temp_stack.pop(); 
 
            }

            temp_stack.push(make_pair(temperatures[i], i));
        }

        return answer;
    }
};
