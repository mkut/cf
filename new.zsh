#!/bin/zsh
if [ "$2" = "cpp" ]
then
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
elif [ "$2" = "hs" ]
then
	cp -r ${SP_PATH}/default.hs \!$1
	cat > \!$1/haskell.hs << EOS
main = do
EOS
else
	echo "Choose language(cpp/hs)."
fi
