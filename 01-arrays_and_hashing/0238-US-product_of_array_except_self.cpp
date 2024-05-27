/* 238. Product of Array Except Self --> unsuccessfully solved
 * Link: https://leetcode.com/problems/product-of-array-except-self/description/
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // we want to get two arrays:
            // 1. prefix: the product of all the elements of 0 to i
            // 2. postfix: the product of all the elements of n to i
        // then, we can find the product of all numbers except i by using
        // these two arrays --> answer = prefix[i-1] * postfix[i+1]

        vector<int> answer;

        vector<int> prefix (nums.size(), 1); 
        vector<int> postfix (nums.size(), 1); 

        // construct prefix array
        for (int i = 1; i < nums.size(); ++i)
            prefix[i] = prefix[i-1] * nums[i - 1];
        
        // construct postfix array
        for (int i = nums.size() - 2; i > -1; --i)
            postfix[i] = postfix[i+1] * nums[i + 1];
        
        // construct answer array
        for (int i = 0; i < nums.size(); ++i)
            answer.push_back(prefix[i] * postfix[i]);

        return answer;
    }
};
