/* 0242 - Valid Anagram
 * Link: https://leetcode.com/problems/valid-anagram/description/
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        // add the letters of s to an unordered mpa
        // increase the value of the unordered map by 1
        // everytime we see that letter in the string
        // go through the letters of t and subtract one
        // everytime you see the letter appear

        std::unordered_map<char, int> map;

        // set all the values to the zero
        for (int i = 0; i < s.size(); ++i)
        {
            map[s.at(i)] = 0;
        }

        // add one everytime you see letter
        for (int i = 0; i < s.size(); ++i)
        {
            map[s.at(i)] += 1;
        }

        // subtract one everytime you see letter in t
        for (int i = 0; i < t.size(); ++i)
        {
            map[t.at(i)] -= 1;
        }

        for (auto iter = map.begin(); iter != map.end(); ++iter)
        {
            if (iter->second != 0)
                return false;
        }

        return true;
        
    }
};
