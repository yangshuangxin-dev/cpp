#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string Transpose(const string &str)
    {
        int len = str.size();
        int n, i;
        string tmp = str;

        for (n = 1; n <= 100; n++)
        {
            if (n * n == len)
            {
                break;
            }
        }

        if (n == 101)
        {
            tmp = "ERROR";
            return tmp;
        }

        for (i = 0; i < len; i++)
        {
            tmp[i / n + i % n * n] = str[i];
        }

        return tmp;
    }
};

int main()
{
    string str;
    cin >> str;

    Solution solu;
    string output = solu.Transpose(str);
    cout << output << endl;

    return 0;
}