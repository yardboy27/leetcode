/* 1. - Two Sum
 * Link: https://leetcode.com/problems/two-sum/description/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // add all numbers, indices to unordered map
        // then loop through again and see if 
        // the target - num is in set

        // problem is when we have [5, 5] as input

        // WHY IS THIS NOT A PROBLEM??? do we just have enough
        // buckets to where it also takes into account
        // the value? confused as to why this would work?

        std::unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i)
        {
            map[nums.at(i)] = i;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            int difference = target - nums.at(i);

            auto iter = map.find(difference);

            if (iter != map.end()){
                int j = iter->second;

                if (i < j)
                    return {i, j};
                else if (i > j)
                    return {j, i};
                
            }
        }

        return {0, 0};
    }
};
