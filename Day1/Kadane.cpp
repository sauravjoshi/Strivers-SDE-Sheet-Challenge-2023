#include <bits/stdc++.h>
using namespace std;

// If there is a group of numbers within an array that adds up to a negative value, it will always make our final result smaller.
// Therefore, this kind of group cannot be included in the group of numbers that has the largest sum.

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int maxi = nums[0];
        int sum = 0;

        for (auto num : nums)
        {
            sum += num;
            maxi = max(maxi, sum);
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return maxi;
    }
};