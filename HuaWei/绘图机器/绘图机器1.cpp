#include <bits/stdc++.h>
using namespace std;
unsigned int GetMinArea(int,const vector<pair<int, int>>& );
int main()
{
    int num, stopPoint;
    cin >> num >> stopPoint;

    vector<pair<int, int>> operations;
    for (int loop = 0; loop < num; loop++)
    {
        int x, value;
        cin >> x >> value;
        operations.emplace_back(make_pair(x, value));
    }

    cout << GetMinArea(stopPoint, operations) << endl;
    return 0;
}

unsigned int GetMinArea(int stopPoint, const vector<pair<int, int>> &operations)
{
    int curx = 0;
    int cury = 0;
    int res = 0;
    for (auto p : operations)
    {
        res += (p.first - curx) * abs(cury);
        curx = p.first;
        cury += p.second;
    }

    res += (stopPoint - curx) * abs(cury);
    return res;
}