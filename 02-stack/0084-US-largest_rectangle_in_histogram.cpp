/* 84. Largest Rectangle in Histogram
 * Link: https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // lets move from left to right. we will only consider a rectangle if it can be extended to the right
        // when we hit a height that is less than the top element, then we can no longer consider that height
        // so, we will find the area that the height could have made and see if that is greater than our 
        // max area. then we will pop that height from our stack, or out of consideration

        int max_area = 0;
        stack<pair<int, int>> height_stack; // index, height --> index is the starting index for that height

        for (int i = 0; i < heights.size(); ++i)
        {
            int start_index = i;
            while(!height_stack.empty() && height_stack.top().second > heights[i])
            {
                int curr_area = height_stack.top().second * (i - height_stack.top().first);
                max_area = max(curr_area, max_area);

                start_index = height_stack.top().first;
                height_stack.pop();
            }

            height_stack.push( {start_index, heights[i]} );
        }

        // now let us clean up the stack and make sure there are no remaining elements
        while (!height_stack.empty())
        {
            int curr_area = height_stack.top().second * (heights.size() - height_stack.top().first);
            max_area = max(curr_area, max_area);

            height_stack.pop();
        }

        return max_area;
    }
};
