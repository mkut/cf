/* aoj header */

pair<int,int> find_equipment(vector<string> equipment_name[3], string name)
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < equipment_name[i].size(); j++)
			if(equipment_name[i][j] == name)
				return pair<int,int>(i, j);
}

int main()
{
	int n; cin >> n;
	vector<string> equipment_name[3] = {};
	vector<int> equipment_power[3] = {}, equipment_size[3] = {};
	int num_size = 0;
	for(int i = 0; i < n; i++)
	{
		string name, _class; cin >> name >> _class;
		int pow[3], size; cin >> pow[0] >> pow[1] >> pow[2] >> size;
		num_size += size;
		int equipment_no = _class == "weapon" ? 0 : (_class == "armor" ? 1 : 2);
		equipment_name[equipment_no].push_back(name);
		equipment_power[equipment_no].push_back(pow[equipment_no]);
		equipment_size[equipment_no].push_back(size);
	}
	int k; cin >> k;
	vector<string> resident_name[3] = {};
	vector<int> resident_power[3] = {}, equipment_cur_power[3] = {equipment_power[0], equipment_power[1], equipment_power[2]};
	for(int i = 0; i < k; i++)
	{
		string res_name, _class, home;
		int bonus;
		cin >> res_name >> _class >> bonus >> home;
		pair<int,int> pos = find_equipment(home);
		int resident_no = _class == "gladiator" ? 0 : (_class == "sentry" ? 1 : 2);
		if(resident_no == pos.first)
			equipment_cur_power[pos.first][pos.second] += bonus;
	}

	if(k >= num_size)
	{
		for(int i = 0; i < 3; i++)
		{

		}
	}
	return 0;
}
