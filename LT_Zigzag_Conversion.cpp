// Problem Link : https://leetcode.com/problems/zigzag-conversion/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


string convert(string s, int numRows)
{
    if (numRows == 1 || numRows >= s.size())
        return s;   // Handle edge cases

    vector<string> rows(min(numRows, int(s.size()))); // Create rows for zigzag
    int curRow = 0;                                   // Current row index
    bool goingDown = false;                           // Direction flag

    for (char c : s)
    {
        rows[curRow] += c;    // Add character to the current row
        
        // Change direction if we hit the top or bottom row

        if (curRow == 0 || curRow == numRows - 1)
            goingDown = !goingDown;
        curRow += goingDown ? 1 : -1;   // Move to the next row
    }

    string result;
    for (string row : rows)
        result += row;  // Concatenate all rows
    return result;     // Return the final zigzag string
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = convert(s, numRows);
    cout << "Input: " << s << ", numRows: " << numRows << endl;
    cout << "Output: " << result << endl;
    return 0;
}