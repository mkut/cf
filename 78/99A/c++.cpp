/* aoj header */

int main()
{
	string str;
	cin >> str;
	int pos = str.find('.');
	if(str[pos-1] == '9')
		cout << "GOTO Vasilisa." << endl;
	else
		cout << str.substr(0, pos-1) << (char)(str[pos-1] + (str[pos+1] >= '5' ? 1 : 0)) << endl;
	return 0;
}
