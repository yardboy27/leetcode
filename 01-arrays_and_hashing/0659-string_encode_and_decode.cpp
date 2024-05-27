/* 659. String Encode and Decode
 * Link: https://neetcode.io/problems/string-encode-and-decode
 */

class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (string str : strs)
        {
            result += to_string(str.size()) + '#' + str;
        }

        cout << result << endl;

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        // first calculate how long the word is
        // then iterate through the string until that
        // iterator is done

        int i = 0;

        string substr_char_len = "";
        int substr_len = 0;

        while (i < s.size())
        { // trying to find where the length of word
            if (s.at(i) == '#')
            { // if we have found the lenght of the word
                ++i;
                substr_len = stoi(substr_char_len);
                string substr = "";

                for (int j = 0; j < substr_len; ++j)
                {
                    substr += s.at(i);
                    ++i;
                }

                result.push_back(substr);

                // reset the variables
                substr_char_len = "";
                substr_len = 0;
            }
            else
            { // if we are still looking for the start of the word
                substr_char_len += s.at(i);
                ++i;
            }
        }

        return result;
    }
};
