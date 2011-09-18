/* aoj header */
#include <map>

int main()
{
	int n, m;
	double k;
	cin >> n >> m >> k;
	map<string, int> skills;
	for(int i = 0; i < n; i++)
	{
		string name;
		int level;
		cin >> name >> level;
		if(level * k >= 100)
			skills[name] = level * k;
	}
	for(int i = 0; i < m; i++)
	{
		string name; cin >> name;
		if(!skills.count(name))
			skills[name] = 0;
	}

	cout << skills.size() << endl;
	for(map<string, int>::iterator it = skills.begin(); it != skills.end(); ++it)
		cout << it->first << " " << it->second << endl;
	
	return 0;
}
