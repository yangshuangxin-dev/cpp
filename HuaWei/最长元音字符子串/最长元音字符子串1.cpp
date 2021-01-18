#include<bits/stdc++.h>
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
        }
        else
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
    cin>>input;

    cout<<GetLongestVowelStringLength(input)<<endl;
    return 0;
}