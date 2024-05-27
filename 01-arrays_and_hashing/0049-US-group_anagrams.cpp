/* 49. Group Anagrams --> unsuccessfully solved by myself
 * Link: https://leetcode.com/problems/group-anagrams/description/
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        // this map will have a sorted word as the key
        // and the value is a vector of the strs that
        // equal that key when they are sorted

        // we can sort using non-comparison based sort --> counting sort
        for (string _str : strs)
        {
            // create a vector that represents the alphabet
            vector<int> count(26, 0);
            // loop through word and add to count for frequency of letters
            for (char _char : _str)
                ++count[_char - 'a'];

            // now reconstruct the sorted word
            string key;
            for (int i = 0; i < count.size(); ++i)
            {
                for (int j = 0; j < count.at(i); ++j)
                    key += char(int('a') + i);
                
                // std::cout << i << key << std::endl; // debug
            }

            // now add this word to the unordered map
            map[key].push_back(_str);
        }

        // now create the answer
        vector<vector<string>> answer;
        for ( auto& pair : map )
        {
            answer.push_back(pair.second);
        }

        return answer;
        
    }
};
