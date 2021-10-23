#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int w = sqrt(1.0 * area);
        while (area % w)
        {
            --w;
        }

        return {area / w, w};
    }
};