/* 0217 - Contains Duplicate
 * Link: https://leetcode.com/problems/contains-duplicate/description/
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std:unordered_set<int> set;
        int num;

        for (int i = 0; i < nums.size(); ++i)
        {
            num = nums.at(i);

            if (set.find(num) != set.end())
                return true;
            

            set.insert(num);
        }

        return false;
    }
};
