#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	int sum = 0;
	int people = 0;
	while(getline(cin, str))
	{
		if(str[0] == '+') people++;
		else if(str[0] == '-') people--;
		else
		{
			sum += people * (str.size() - str.find(":")-1);
		}
	}
	cout << sum << endl;
	return 0;
}