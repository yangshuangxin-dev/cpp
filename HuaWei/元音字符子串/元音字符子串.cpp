/*
题目描述
定义：当一个字符串只有元音字母（aeiouAEIOU）组成，称为元音字符串。
现给定一个字符串，请找出其中最长的元音字符子串，并返回其长度；如果找不到，则返回0。

子串：字符串中任意个连续的字符组成的子序列称为该字符串的子串。

解答要求
时间限制：1000ms, 内存限制：256MB
输入
一个字符串，其长度范围： 0 < length <= 65535。

字符串仅由字符a-z和A-Z组成。

输出
一个整数，表示最长的元音字符子串的长度。

样例
输入样例 1 复制

asdbuiodevauufgh
输出样例 1

3
提示
最长元音子串为 “uio” 或 “auu”，其长度都为3，因此输出3
*/

#include <bits/stdc++.h>
using namespace std;
int GetLongestVowelStringLength(const string& input)
{
    const string ALL_VOWEL="aeiouAEIOU";
    int res=0;
    int tmp=0;
    for(auto ch:input)
    {
        if(ALL_VOWEL.find(ch)!=string::npos)
        {
            tmp++;
        }else
        {
            res=max(res,tmp);
            tmp=0;
        }
        
    }
    res=max(res,tmp);
    return res;
}

int main()
{
    string input;
    cin >> input;

    cout << GetLongestVowelStringLength(input) << endl;
    return 0;
}
