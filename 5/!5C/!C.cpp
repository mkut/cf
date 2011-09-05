#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main()
{
	map<int,int> ans;
	map<int,int> ansnum;

	string str;
	cin >> str;
	int nest = 0;
	int cur = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == '(') nest++;
		else nest--;
		
		if(ans.count(nest) == 0) ans[nest] = 0;
		cur++;
		if(str[i] == ')')
		{
			if(nest < 0)
			{
				cur = 0;
				nest = 0;
			}
			else if(ans[nest] == cur - nest)
			{
				ansnum[nest]++;
			}
			else if(ans[nest] < cur - nest)
			{
				ans[nest] = cur - nest;
				ansnum[nest] = 1;
			}
		}
	}
	int maxL = 0;
	int maxnumL = 1;
	for(int i = 0; ans.count(i) > 0; i++)
	{
			cout << ans[i] << ansnum[i] << endl;
		if(maxL == ans[i])
		{
			maxnumL += ansnum[i];
		}
		if(maxL < ans[i])
		{
			maxL = ans[i];
			maxnumL = ansnum[i];
		}
	}

	ans = map<int,int>();
	ansnum = map<int,int>();
	reverse(str.begin(), str.end());
	nest = 0;
	cur = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == ')') nest++;
		else nest--;
		
		if(ans.count(nest) == 0) ans[nest] = 0;
		cur++;
		if(str[i] == '(')
		{
			if(nest < 0)
			{
				cur = 0;
				nest = 0;
			}
			else if(ans[nest] == cur - nest)
			{
				ansnum[nest]++;
			}
			else if(ans[nest] < cur - nest)
			{
				ans[nest] = cur - nest;
				ansnum[nest] = 1;
			}
		}
	}
	int maxR = 0;
	int maxnumR = 1;
	for(int i = 0; ans.count(i) > 0; i++)
	{
		if(maxR == ans[i])
		{
			maxnumR += ansnum[i];
		}
		if(maxR < ans[i])
		{
			maxR = ans[i];
			maxnumR = ansnum[i];
		}
	}
	if(maxL > maxR)
	{
		maxL = maxR;
		maxnumL = maxnumR;
	}
	
	cout << maxL << " " << (maxL == 0 ? 1 : maxnumL) << endl;
}