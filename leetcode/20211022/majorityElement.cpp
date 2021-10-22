#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> hash;
        vector<int> ans;
        for (auto &num : nums)
        {
            hash[num]++;
        }

        int len = nums.size() / 3;
        for (auto &val : hash)
        {
            if (val.second > len)
            {
                ans.emplace_back(val.first);
            }
        }

        return ans;
    }
};