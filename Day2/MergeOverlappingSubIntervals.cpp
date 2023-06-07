#include <bits/stdc++.h>
using namespace std;

// The logic is to maintain a reference vector that is increasing from left to right after sorting.
// If the newer subinterval lies out of bound push this elongated subinterval into the ans.
// Else further elongate this interval as far as possible.

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];

        for (auto interval : intervals)
        {

            if (interval[0] <= temp[1])
            {
                int maxi = max(interval[1], temp[1]);
                temp[1] = maxi;
            }
            else
            {
                ans.push_back(temp);
                temp = interval;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};