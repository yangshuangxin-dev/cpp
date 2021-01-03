#include <iostream>
#include <bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


bool dfs(vector<vector<char> > &data ,vector<vector<bool> > &flag,string s,int k,int i,int j)
{
	if(i<0||i>=data.size()||j<0||j>=data[0].size()||s[k]!=data[i][j]||flag[i][j])
	{
		return false;
	}
	
	if(k==s.size()-1)
	{
		return true;
	}
	
	flag[i][j]=true;
	
	if( dfs(data,flag,s,k+1,i+1,j)||
	    dfs(data,flag,s,k+1,i-1,j)||
	    dfs(data,flag,s,k+1,i,j+1)||
	    dfs(data,flag,s,k+1,i,j-1)
	)
	{
		return true;
	}
	
	flag[i][j]=false;
	return false;
}

bool findStr(vector<vector<char> > &data ,string s,int &a,int& b)
{
	vector<vector<bool> > flag(data.size(),vector<bool>(data[0].size(),false));
	for(int i=0;i<data.size();i++)
	{
		for(int j=0;j<data[0].size();j++)
		{
			if(dfs(data,flag,s,0,i,j))
			{
				a=i;
				b=j;
				return true;
			}
		}	
	}
	
	return false;
}


int main(int argc, char **argv)
{

    int m, n;
    cin >> n >> m;
 	
 	string str;
 	cin>>str;
 	
 	vector<vector<char> > data;
 	
 	for(int i=0;i<n;i++)
 	{
 		vector<char> tmp;
 		for(int j=0;j<m;j++)
 		{
 			char ch;
 			cin>>ch;
 			tmp.emplace_back(ch);
		 }
		data.emplace_back(tmp);
	 }
	 
	 int i=0,j=0;
	if(findStr(data,str,i,j))
	{
		cout<<i+1<<' '<<j+1<<endl;
	 } 
	 else
	 {
	 	cout<<"NO"<<endl;
	 }
    return 0;
}