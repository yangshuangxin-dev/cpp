#include<bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int lengthOfLongatSubstring (string str)
{
	deque<char> s;
	if(str.empty())
	{
		return 0;
	}
	int sum=0,left=0;
	
	for(int right=0;right<str.size();right++)
	{
		while(find(s.begin(),s.end(),str[right])!=s.end())
		{
			s.pop_front();
			left++;
		}
		sum=max(sum,right-left+1);
		s.push_back(str[right]);
	}
	
	return sum;
}

int main(int argc, char** argv) {
	string s="abcdefgeiasdfghjklkjhgfdsazxcvbnmnbvcxzjklmnopq";
	cout<<lengthOfLongatSubstring(s)<<endl;
	getchar();
	int *p=nullptr;
	cout<<"hello world!!!!!!!!"<<endl;
	for(auto i:s)
	{
		cout<<i;
	}
	int k;
	cin>>k;
	return 0;
}