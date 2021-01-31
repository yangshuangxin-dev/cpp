#include <bits/stdc++.h>
using namespace std;

int GetLongertFlawedVowelSubstrLen(const size_t flaw, const string &inptr)
{
    int curFlaw = 0;
    int curMaxLen = 0;
    int left = 0;
    int right = 0;

    string vowel = "aeiouAEIOU";
    while (left < inptr.size() && right < input.size())
    {
        if (vowel.find(input[right]) == string::npos)
        {
            curFlaw++;
        }

        if (curFlaw > flaw)
        {
            while (left < right)
            {
                if (vowel.find(input[left]) == string::npos)
                {
                    curFlaw--;
                }
                left++;

                if (curFlaw <= flaw)
                {
                    break;
                }
            }
        }

        if (curFlaw == flaw && vowel.find(input[left]) != string::npos && vowel.find(input[right]) != string::npos)
        {
            curMaxLen = max(curMaxLen, right - left + 1);
        }

        right++;
    }

    return curMaxLen;
}

int main()
{
    size_t flaw;
    cin >> flaw;

    string input;
    cin >> input;

    cout << GetLongertFlawedVowelSubstrLen(flaw, input) << endl;
    return 0;
}