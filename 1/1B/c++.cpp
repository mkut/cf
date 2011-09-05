#include <milib/template/aoj>
#include <sstream>

class solver
{
private:
	vector<string> vs;
	vector<string> ans;
public:
	//>>[solver
	vs[]:string
	//>>]
	//<<[solver
	ans+_'\n':string
	//<<]
	int ipow(int x, int y)
	{
		int ret = 1;
		each(i : y)
			ret *= x;
		return ret;
	}
	int atoi(string str)
	{
		stringstream ss;
		ss << str;
		int ret;
		ss >> ret;
		return ret;
	}
	int stoi (string str)
	{
		int ret = 0;
		each(i : str.length())
			ret = ret * 26 + str[i] - 'A';
		each(i : str.length())
			ret += ipow(26, i);
		return ret;
	}
	string itos(int x, int len)
	{
		string ret(len, 'A');
		for(int i = len-1; i >= 0; i--)
		{
			ret[i] = x % 26 + 'A';
			x /= 26;
		}
		return ret;
	}
	string itos(int x)
	{
		string ret;
		int len;
		for(len = 0; x >= ipow(26, len); len++)
			x -= ipow(26, len);
		return itos(x, len);
	}
	bool isrc(string str)
	{
		bool cur_num = true;
		int change = 0;
		each(i : str.length())
			if(cur_num && str[i] >= 'A' && str[i] <= 'Z')
				cur_num = false, change++;
			else if(!cur_num && str[i] >= '0' && str[i] <= '9')
				cur_num = true, change++;
		return change > 2;
	}
	string conv(string str)
	{
		if(isrc(str))
		{
			int col = atoi(str.substr(str.find("C")+1));
			int row = atoi(str.substr(1, str.find("C")-1));
			stringstream ss;
			ss << itos(col) << row;
			return ss.str();
		}
		else
		{
			int pos;
			for(pos = 0; str[pos] >= 'A' && str[pos] <= 'Z'; pos++);
			int col = stoi(str.substr(0, pos));
			int row = atoi(str.substr(pos));
			stringstream ss;
			ss << "R" << row << "C" << col;
			return ss.str();
		}
	}
	void solve()
	{
		each(i : vs.size())
			ans.push_back(conv(vs[i]));
	}
};

int main()
{
	solver prob;
	while(cin >> prob)
	{
		prob.solve();
		cout << prob;
		break;
	}
	return 0;
}
