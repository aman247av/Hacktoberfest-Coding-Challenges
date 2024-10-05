#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::min

using namespace std;

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);

string convert(string s, int numRows)
{
    if (numRows == 1 || numRows >= s.size())
        return s; // Handle edge cases

    vector<string> rows(min(numRows, int(s.size()))); // Create rows for zigzag
    int curRow = 0;                                   // Current row index
    bool goingDown = false;                           // Direction flag

    for (char c : s)
    {
        rows[curRow] += c; // Add character to the current row
        // Change direction if we hit the top or bottom row
        if (curRow == 0 || curRow == numRows - 1)
            goingDown = !goingDown;
        curRow += goingDown ? 1 : -1; // Move to the next row
    }

    string result;
    for (string row : rows)
        result += row; // Concatenate all rows
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