// 4 Steps to Solve
// 1. Check from end where a dip occurs or where A[i] < A[i+1]. This is our Break Point;
// 2. Find the element from the end that is greater than the BreakPoint. Traversing from the end gives us the just next number greater than A[BreakPoint].
// 3. Swap the elements at A[BreakPoint] and A[indexGreaterThanBreakPoint].
// 4. To get the immediate greater Permutation, sort the elements from BreakPoint till end of array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {

        int n = nums.size();
        int breakPoint = -1;

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                breakPoint = i;
                break;
            }
        }
        if (breakPoint == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i = n - 1; i > breakPoint; i--)
        {
            if (nums[i] > nums[breakPoint])
            {
                swap(nums[i], nums[breakPoint]);
                break;
            }
        }

        reverse(nums.begin() + breakPoint + 1, nums.end());
    }
};
