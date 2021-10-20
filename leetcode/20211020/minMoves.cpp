#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minMoves(vector<int>& nums) {
        return accumulate(begin(nums),end(nums),0)-*min_element(begin(nums),end(nums))*size(nums);
    }
};