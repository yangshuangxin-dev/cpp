#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i]++;
            if (digits[i] <= 9)
            {
                return digits;
            }
            digits[i] = 0;
        }

        digits.insert(begin(digits), 1);
        return digits;
    }
};