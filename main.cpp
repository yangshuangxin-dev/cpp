#include <iostream>
#include <bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char **argv)
{

    int k, n;
    cin >> k >> n;
    vector<string> strs;
    string s;
    //cout << k << ' ' << n << endl;
    int tmp = n;
    while (tmp--)
    {
        cin >> s;
        strs.emplace_back(s);
    }

    s = strs[k];
    //cout<<s<<endl;
    map<char, string> hash;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == k)
            {
                continue;
            }
            if (hash.count(strs[i][0]) == 0)
            {
                hash[strs[i][0]] = strs[i];
                //strs[i] = "";
            }
            else
            {
                if (hash[strs[i][0]].size() < strs[i].size() || (hash[strs[i][0]].size() == strs[i].size() && strs[i] < hash[strs[i][0]]))
                {
                    hash[strs[i][0]] = strs[i];
                    //strs[i] = "";
                }
            }
        }
        int index = s.size() - 1;
        if (hash.count(s[index]))
        {
            s += hash[s[index]];
            for(int i=0;i<strs.size();i++)
            {
                if(strs[i]==hash[s[index]])
                {
                    strs[i]="";
                    break;
                }
            }
        }
        hash.clear();
    }

    cout << s << endl;
    return 0;
}