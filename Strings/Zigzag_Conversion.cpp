/*

Approach
Create one string for each row.
Traverse the input string once.
Append each character to the current row.
Change direction only when reaching the first or last row.
Concatenate all rows to obtain the final zigzag string.

*/

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = true;

        for (char c : s) {

            rows[currentRow] += c;

            if (currentRow == 0)
                goingDown = true;
            else if (currentRow == numRows - 1)
                goingDown = false;

            currentRow += goingDown ? 1 : -1;
        }

        string result;
        result.reserve(s.size());

        for (const string &row : rows)
            result += row;

        return result;
    }
};