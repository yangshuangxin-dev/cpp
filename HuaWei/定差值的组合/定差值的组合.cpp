/*
题目描述
定差值的组合.cpp
给定一个数组，每个元素的值是唯一的，找出其中两个元素相减等于给定差值 diff 的所有不同组合的个数。

组合是无序的：如：（1, 4)和(4, 1)表示的是同一个组合。
解答要求
时间限制：1000ms, 内存限制：256MB
输入
输入三行:
第一行为一个整数，表示给定差值diff；范围[-50000, 50000]
第二行也为一个数字，表示数组的长度；范围[2, 102400]
第三行为该数组，由单个空格分割的一组数字组成；其中元素的值范围[-20, 102400]

用例保证第三行数字和空格组成的字符串长度不超过 649999

输出
1个整数，表示满足要求的不同组合的个数

样例
输入样例 1 复制

3
5
1 3 2 5 4
输出样例 1

2
提示
数组为[1 3 2 5 4]， 差值 diff 为 3，其中 4 - 1 = 3，5 - 2 = 3，共 2 个组合满足条件，因此输出 2



输入样例 2 复制

-1
3
1 2 3
输出样例 2

2
提示
其中 1 - 2 = -1，2 - 3 = -1，共 2 个组合满足条件，因此输出 2。
*/

int Proc(const vector<int> &arr, int diff)
{
    // 在此添加你的代码
    if (diff == 0)
    {
        return 0;
    }
    auto tmp = arr;
    sort(tmp.begin(), tmp.end(), less<int>());
    int cnt = 0;
    for (int i = 0; i < tmp.size(); ++i)
    {
        if (binary_search(tmp.begin(), tmp.end(), tmp[i] + diff))
        {
            cnt++;
        }
    }
    return cnt;
}

// 以下为考题输入输出框架，此部分代码不建议改动
int main()
{
    string line;
    getline(cin, line);
    int diff = stoi(line);

    getline(cin, line);
    int n = stoi(line);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << Proc(arr, diff) << endl;
    return 0;
}
