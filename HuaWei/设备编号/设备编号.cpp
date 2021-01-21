#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int GetNormalDeviceNum(int start, int end)
    {
        int result = 0;
        for (int i = start; i <= end; i++)
        {
            string s = to_string(i);
            if (s.find("4") != string::npos || s.find("18") != string::npos)
            {
                continue;
            }
            result++;
        }

        return result;
    }
};

inline int ReadInt()
{
    int number;
    cin >> number;
    return number;
}

int main()
{
    int start = ReadInt();
    int end = ReadInt();

    Solution solu;

    int result = solu.GetNormalDeviceNum(start, end);
    cout << result<<endl;

    return 0;
}