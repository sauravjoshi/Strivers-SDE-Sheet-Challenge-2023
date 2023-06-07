#include <bits/stdc++.h>
using namespace std;

// Logic is to maintain the lowest left and the highest right. [Crest and Trough]
// The difference of which gives us the max Profit

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int leftMin = 1e9;
        int maxi = -1e9;

        for (auto price : prices)
        {

            leftMin = min(leftMin, price);
            maxi = max(maxi, price - leftMin);
        }

        return maxi;
    }
};