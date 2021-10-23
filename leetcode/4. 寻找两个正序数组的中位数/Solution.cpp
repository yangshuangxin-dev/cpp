#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int len1 = nums1.size();
        int len2 = nums2.size();

        int sumlen = len1 + len2;

        int left = -1, right = -1;
        int start1 = 0, strat2 = 0;

        for (int i = 0; i < sumlen / 2; i++)
        {
            left = right;
            if (start1 < len1 && (strat2 >= len2 || nums1[start1] < nums2[strat2]))
            {
                right = nums1[start1++];
            }
            else
            {
                right = nums2[strat2++];
            }
        }

        if ((sumlen & 1) == 0)
        {
            return (left + right) / 2.0;
        }
        else
        {
            return right;
        }
    }
};