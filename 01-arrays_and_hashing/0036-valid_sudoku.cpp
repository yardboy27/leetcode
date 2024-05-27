/* 36. Valid Suduko
 * Link: https://leetcode.com/problems/valid-sudoku/description/
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       // use three unordered sets 
            // 1. horizontal set --> reset after each row
            // 2. grid set --> have three of these, reset
            // after 3 rows
            // 3. vertical set --> reset after each row
        
        unordered_set<char> row_check;
        vector<unordered_set<char>> col_check (9);
        vector<unordered_set<char>> grid_check (3);

        int iterations = 1;

        for (int row = 0; row < board.size(); ++row)
        {
            for (int col = 0; col < board[row].size(); ++col)
            {
                char val = board[row][col];
                // cout << val; // debug

                if (val == '.')
                    continue;

                // check the unordered sets
                if (row_check.find(val) != row_check.end())
                    return false;
                else if (col_check[col].find(val) != col_check[col].end())
                    return false;
                else if (grid_check[col/3].find(val) != grid_check[col/3].end() )
                    return false;
                
                // now add to the sets if all false
                row_check.insert(val);
                col_check[col].insert(val);
                grid_check[col/3].insert(val);
            }
            // cout << endl; // debug

            // clear out the appropriate sets
            row_check.clear();
            
            if (iterations % 3 == 0)
                for (int i = 0; i < grid_check.size(); ++i)
                    grid_check[i].clear();
            
            ++iterations;
        }

        return true;
    }
};
