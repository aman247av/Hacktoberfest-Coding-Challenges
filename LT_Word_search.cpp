// https: // leetcode.com/problems/word-search/

#include <bits/stdc++.h>

using namespace std;

class Solution
{

    bool sSearch(int row, int col, string &s, vector<vector<char>> &mat, int n, int m, int cur)
    {
        // cout<<"Calling at: "<<cur<<"   "<<s.length()<<endl;
        if (cur == s.length())
        {
            // cout<<"Finally returning true!"<<endl;
            return true;
        }

        if (row < 0 || col < 0 || row >= m || col >= n || mat[row][col] != s[cur] || mat[row][col] == '!')
        {
            return false;
        }

        bool east, west, north, south;

        char c = mat[row][col];
        mat[row][col] = '!';

        east = sSearch(row, col + 1, s, mat, n, m, cur + 1);
        west = sSearch(row, col - 1, s, mat, n, m, cur + 1);
        north = sSearch(row + 1, col, s, mat, n, m, cur + 1);
        south = sSearch(row - 1, col, s, mat, n, m, cur + 1);

        mat[row][col] = c;

        return east || west || north || south;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {

        int row = board.size(), col = board[0].size();
        if (word.length() > (row * col))
        {
            return false;
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == word[0])
                {
                    // cout<<"Found at location: "<<i<<","<<j<<"  Value"<<board[i][j]<<endl;
                    if (sSearch(i, j, word, board, col, row, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};