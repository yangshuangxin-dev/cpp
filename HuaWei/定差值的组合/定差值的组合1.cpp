#include <bits/stdc++.h>
using namespace std;

int Proc(const vector<int> &arr, int diff)
{
    if (diff == 0)
    {
        return 0;
    }

    auto tmp = arr;
    sort(tmp.begin(), tmp.end(), less<int>());
    int cnt = 0;
    for (int i = 0; i < tmp.size(); i++)
    {
        if (binary_search(tmp.begin(), tmp.end(), tmp[i] + diff))
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    string line;
    getline(cin, line);
    int diff = stoi(line);

    getline(cin, line);
    int n = stoi(line);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Proc(arr, diff) << endl;
    return 0;
}