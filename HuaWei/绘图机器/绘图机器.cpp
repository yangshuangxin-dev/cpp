
/*
题目描述
绘图机器的绘图笔初始位置在原点（0, 0），机器启动后其绘图笔按下面规则绘制直线：
1）尝试沿着横向坐标轴正向绘制直线，直到给定的终点值E。
2）期间可通过指令在纵坐标轴方向进行偏移，并同时绘制直线，偏移后按规则1 绘制直线；指令的格式为X offsetY，表示在横坐标X 沿纵坐标方向偏移，offsetY为正数表示正向偏移，为负数表示负向偏移。

给定了横坐标终点值E、以及若干条绘制指令，请计算绘制的直线和横坐标轴、以及 X=E 的直线组成图形的面积。

解答要求
时间限制：1000ms, 内存限制：256MB
输入
首行为两个整数 N E，表示有N条指令，机器运行的横坐标终点值E。
接下来N行，每行两个整数表示一条绘制指令X offsetY，用例保证横坐标 X 以递增排序方式出现，且不会出现相同横坐标 X 。
取值范围：0 < N <= 10000, 0 <= X <= E <= 20000, -10000 <= offsetY <= 10000。

输出
一个整数，表示计算得到的面积，用例保证，结果范围在 0~4294967295 内

样例
输入样例 1 复制

4 10
1 1
2 1
3 1
4 -2
输出样例 1

12
提示


输入样例 2 复制

2 4
0 1
2 -2

输出样例 2

4
*/

#include <iostream>
#include <vector>

using namespace std;
unsigned int GetMinArea(int stopPoint, const vector<pair<int, int>> &operations)
{
    int curx=0;
    int cury=0;
    int res=0;
    for(auto p:operations)
    {
        res+=(p.first-curx)*abs(cury);
        curx=p.first;
        cury+=p.second;
    }

    res+=(stopPoint-curx)*abs(cury);
    return res;
}

int main()
{
    int num, stopPoint;
    cin >> num >> stopPoint;
    
    vector<pair<int, int>> operations;
    for (int loop = 0; loop < num; loop++) {
        int x, value;
        cin >> x >> value;
        operations.push_back(make_pair(x, value));
    }
  
    cout << GetMinArea(stopPoint, operations) << endl;
    
    return 0;
}
