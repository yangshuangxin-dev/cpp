#include <bits/stdc++.h>
using namespace std;

int ClusterLatency(const vector<int> &arr)
{
    auto tmp = arr;
    sort(tmp.begin(), tmp.end());

    int len = tmp.size();
    int key = len % 2 ? tmp[(len - 1) / 2] : tmp[len / 2];

    int cnt = 0;
    for (auto i : arr)
    {
        cnt += abs(key - i);
    }

    return cnt;
}

int main()
{
    string line;
    getline(cin, line);
    int n = stoi(line);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << ClusterLatency(arr) << endl;
    return 0;
}