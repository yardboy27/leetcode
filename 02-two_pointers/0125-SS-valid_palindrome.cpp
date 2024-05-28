/* 125. Valid Palindrome
 * Link: https://leetcode.com/problems/valid-palindrome/description/
 */

class Solution {
public:
    bool isPalindrome(string s) {
        // one pointer starts at the left
        // one pointer starts at the right
        // keep incrementing the pointers --> if left != right, return false

        string clean_string;

        // eliminate all non-alphanumeric characters and convert uppercase to lowercase
        for (int i = 0; i < s.size(); ++i)
        {
            char _char = s[i];
            int _char_value = (int)_char;

            if ( _char_value >= 97 && _char_value <= 122 ) // if lowercase
                clean_string.push_back(_char);
            else if ( _char_value >= 65 && _char_value <= 90 ) // if uppercase
                clean_string.push_back( char( (int)_char + 32 ) );
            else if ( _char_value >= 48 && _char_value <= 57)
                clean_string.push_back(_char);
        }

        int left_iter = 0;
        int right_iter = clean_string.size() - 1;

        while (left_iter < right_iter)
        {
            if (clean_string[left_iter] != clean_string[right_iter])
                return false;

            ++left_iter; --right_iter;
        }

        return true;
    }
};
