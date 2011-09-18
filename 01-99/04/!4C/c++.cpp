#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<string, int> number;
	
	while(n--)
	{
		string input;
		cin >> input;
		if(number.count(input) > 0)
		{
			cout << input << number[input]++ << endl;
		}
		else
		{
			number[input]++;
			cout << "OK" << endl;
		}
	}
	return 0;
}