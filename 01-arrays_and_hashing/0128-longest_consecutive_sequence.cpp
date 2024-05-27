/* 128. Longest Consecutive Sequence
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/description/
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort the elements
        // go through elements and see if there are any elements
        // that are more than 1 off

        sort(nums.begin(), nums.end());

        if (nums.size() == 0)
            return 0;

        int max_consec = 0;
        int curr_consec = 1;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i+1] != nums[i]) // this conditional i found from a solution. i didnt think about just skipping
            { // the checks if they were the same; i thought that something special happened if they were the same depending on their location
                if (nums[i+1] - nums[i] != 1)
                {
                    max_consec = (max_consec < curr_consec) ? curr_consec : max_consec;
                    curr_consec = 1;
                }
                else
                {
                    ++curr_consec;
                }
            }
        }

        max_consec = (max_consec < curr_consec) ? curr_consec : max_consec;

        return max_consec;
    }
};
