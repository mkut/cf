#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	string str, a, b;
	cin >> str >> a >> b;
	bool forward = false, backward = false;
	int pos = str.find(a);
	if(pos != string::npos)
	{
		if(str.find(b, pos + a.length()) != string::npos)
		{
			forward = true;
		}
	}
	pos = str.find(b);
	if(pos != string::npos)
	{
		if(str.find(a, pos + b.length()) != string::npos)
		{
			backward = true;
		}
	}
	if(forward && backward)
		cout << "both" << endl;
	else if(forward && !backward)
		cout << "forward" << endl;
	else if(!forward && backward)
		cout << "backward" << endl;
	else
		cout << "fantasy" << endl;
	return 0;
}
