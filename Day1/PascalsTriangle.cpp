#include <bits/stdc++.h>
using namespace std;

// Since we are generating a row for every row TC = O(n^2). No additional Space O(1)
// Current Col val PT[i][j] = PT[i-1][j-1] + PT[i-1][j]
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {

        vector<vector<int>> PT;

        PT.push_back({1});

        for (int i = 1; i < numRows; i++)
        {
            vector<int> running;
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    running.push_back(1);
                }
                else
                {
                    int val = PT[i - 1][j] + PT[i - 1][j - 1];
                    running.push_back(val);
                }
            }
            PT.push_back(running);
        }
        return PT;
    }
};