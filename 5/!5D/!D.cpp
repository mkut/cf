#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;


int main()
{
	double a, v, l, d, w;
	cin >> a >> v >> l >> d >> w;

	double limit1 = min(w, v);
	double limit2 = v;

	double area1 = limit1 / a * limit1 / 2;
	double time1 = limit1 / a;
	double area2 = area1 > d ? area1 : d;
	double time2 = (0 > d-area1 ? 0 : d-area1) / limit1 + time1;
	double area3 = (limit2 - limit1) / a * (limit2 + limit1) / 2 + area2;
	double time3 = (limit2 - limit1) / a + time2;
	if(l <= area1)
	{
		printf("%.8f\n", sqrt(2*l/a));
	}
	else if(l <= area2)
	{
		printf("%.8f\n", (l-area1)/limit1 + time1);
	}
	else if(l <= area3)
	{
		printf("%.8f\n", (sqrt(limit1*limit1 + 2 * a * (l-area2)) - limit1)/a + time2);
	}
	else
	{
		printf("%.8f\n", (l-area3)/limit2 + time3);
	}
	//printf("%.8f,%.8f,%.8f\n", area1, area2, area3);
	//printf("%.8f,%.8f,%.8f\n", time1, time2, time3);
}