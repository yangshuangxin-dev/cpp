#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int GetMacNum(string ins)
    {
        set<string> s;
        for (int i = 0; i + 17 <= ins.size(); i++)
        {
            string tmp = ins.substr(i, 17);
            if (IsValid(tmp))
            {
                Reshape(tmp);
                s.insert(tmp);
            }
        }

        return s.size();
    }

    void Reshape(string &s)
    {
        for (auto &ch : s)
        {
            if (ch == ':')
            {
                ch = '-';
            }
            ch = toupper(ch);
        }
    }

    bool IsHex(char ch)
    {
        if (ch >= '0' && ch <= '9')
        {
            return true;
        }

        if (ch >= 'a' && ch <= 'f')
        {
            return true;
        }

        if (ch >= 'A' && ch <= 'F')
        {
            return true;
        }

        return false;
    }

    bool IsValid(string s)
    {
        int tmp = max(count(s.begin(), s.end(), '-'), count(s.begin(), s.end(), ':'));
        if (tmp != 5)
        {
            return false;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if ((i + 1) % 3 != 0 && !IsHex(s[i]))
            {
                return false;
            }
        }

        return true;
    }
};

inline string ReadLine()
{
    string line;
    getline(cin, line);
    return line;
}

int main()
{
    string instr = ReadLine();
    Solution solu;
    int res = solu.GetMacNum(instr);
    cout << res << endl;
    return 0;
}