#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

string pad(string str, int size)
{
	static bool left = true;
	string r = "*";
	for(int i = 0; i < (size - str.length() + (left ? 0 : 1))/2; i++)
	{
		r += ' ';
	}
	r += str;
	for(int i = 0; i < (size - str.length() + (left ? 1 : 0))/2; i++)
	{
		r += ' ';
	}
	r += '*';
	if((size - str.length()) % 2 == 1) left = !left;
	return r;
}

int main()
{
	vector<string> input;
	string str;
	int size = 0;
	while(getline(cin, str))
	{
		input.push_back(str);
		size = max(size, (int)str.length());
	}
	for(int i = 0; i < size+2; i++)
	{
		cout << '*';
	}
	cout << endl;
	for(int i = 0; i < input.size(); i++)
	{
		cout << pad(input[i], size) << endl;
	}
	for(int i = 0; i < size+2; i++)
	{
		cout << '*';
	}
	cout << endl;
	return 0;
}