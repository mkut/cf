#!/bin/zsh
cp -r ${SP_PATH}/default \!$1
cat > \!$1/c++.cpp << EOS
#include <milib/template/aoj>

class solver
{
private:
public:
	//>>[solver
	//>>]
	//<<[solver
	//<<]
	void solve()
	{
	}
};

int main()
{
	solver prob;
	while(cin >> prob)
	{
		prob.solve();
		cout << prob;
	}
	return 0;
}
EOS
