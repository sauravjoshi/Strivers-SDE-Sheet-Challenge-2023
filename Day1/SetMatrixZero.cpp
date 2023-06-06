#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/set-matrix-zeroes/editorial/
// 2 * (M*N) Time and (M + N) Space
// Used extra 2 vectors to mark the zero position

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        vector<int> row(matrix.size(), -1);
        vector<int> col(matrix[0].size(), -1);

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (row[i] == 0 || col[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// Instead of Using Extra Vectors we maintain knowledge by taking 1st row and 1st col
// Tricky part is to avoid duplicacy of matrix[0][0] cell twice. We want to separate the 1st row and 1st col so that they do not affect each other
// Thus 1st row is governed by cell matrix[0][0] and first col is governed by col0 variable
// 2 * (M*N) Time and O(1) Space
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {

        bool isCol = false;
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
            {
                isCol = true;
            }

            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 1; j < matrix[0].size(); j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (isCol)
        {
            for (int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};