#include <bits/stdc++.h>
using namespace std;

// Most optimized using O(1) Space and a linear scan.
// Maintain 2-Pointer for zero and two for correct position insertion and updation
// Trick is that for two pointer not to increment the currentPointer as the current element coming at currentPointer need not be zero.
// We are maintaining 0s from left and 1s from right.

// This problem is a variation of the popular Dutch National flag algorithm. /

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {

        int n = nums.size();
        int zeroPointer = 0;
        int twoPointer = n - 1;

        int currentPointer = 0;

        while (currentPointer <= twoPointer)
        {
            if (nums[currentPointer] == 0)
            {
                swap(nums[currentPointer], nums[zeroPointer]);
                currentPointer++;
                zeroPointer++;
            }
            else if (nums[currentPointer] == 2)
            {
                swap(nums[currentPointer], nums[twoPointer]);
                twoPointer--;
            }
            else
            {
                currentPointer++;
            }
        }
    }
};