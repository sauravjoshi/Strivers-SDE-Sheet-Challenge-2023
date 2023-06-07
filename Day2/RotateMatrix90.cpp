#include <bits/stdc++.h>
using namespace std;

// The tricky part is to set the bounds while swapping. If done from 0 to n, matrix we swapped and then re-swapped.
// Instead the swapping should be done dependent on the row index, so suitable elements are picked.
// Logic is to take the Transpose of the matrix and mirror the resultant by doing a reverse.
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};