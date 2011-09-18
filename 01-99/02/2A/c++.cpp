#include <milib/template/aoj>
#include <vector>
#include <map>

struct hist
{
	string name;
	int point;
	friend istream& operator>>(istream& is, hist& h) {
		cin >> h.name >> h.point;
	}
};

class solver
{
private:
	vector<hist> hs;
	string ans;
public:
	//>>[solver
	hs[]:hist
	//>>]
	//<<[solver
	ans
	//<<]
	void solve()
	{
		map<string, int> score;
		each(h : hs of vector<hist>)
			score[h->name] += h->point;
		vector<string> hiname;
		int hiscore = -1000000;
		each(s : score of map<string, int>)
		{
			if(s->second > hiscore)
			{
				hiname = vector<string>();
				hiname.push_back(s->first);
				hiscore = s->second;
			}
			else if(s->second == hiscore)
			{
				hiname.push_back(s->first);
			}
		}
		score.clear();
		each(h : hs of vector<hist>)
		{
			if(find(hiname.begin(), hiname.end(), h->name) != hiname.end())
			{
				score[h->name] += h->point;
				if(score[h->name] >= hiscore)
				{
					ans = h->name;
					return;
				}
			}
		}
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
