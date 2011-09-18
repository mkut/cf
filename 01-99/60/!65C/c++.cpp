#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define EPS 1e-7

double norm(double x, double y, double z)
{
	return sqrt(x*x+y*y+z*z);
}

int main()
{
	int n; cin >> n;
	vector<double> x(n+1), y(n+1), z(n+1);
	for(int i = 0; i < n+1; i++)
		cin >> x[i] >> y[i] >> z[i];
	double vp, vs, xp, yp, zp;
	cin >> vp >> vs >> xp >> yp >> zp;
	vector<double> t(n+1);
	for(int i = 1; i < n+1; i++)
		t[i] = t[i-1] + norm(x[i]-x[i-1], y[i]-y[i-1], z[i]-z[i-1]) / vs;
	int done = 0;
	for(int i = 1; i < n+1; i++)
	{
		double AX = (x[i]-x[i-1])/(t[i]-t[i-1]);
		double BX = x[i-1] - xp;
		double AY = (y[i]-y[i-1])/(t[i]-t[i-1]);
		double BY = y[i-1] - yp;
		double AZ = (z[i]-z[i-1])/(t[i]-t[i-1]);
		double BZ = z[i-1] - zp;
		double a = AX * AX + AY * AY + AZ * AZ - vp * vp;
		double b = 2 * BX * AX + 2 * BY * AY + 2 * BZ * AZ - 2 * t[i-1] * vp * vp;
		double c = BX * BX + BY * BY + BZ * BZ - t[i-1] * t[i-1] * vp * vp;
		double d = b*b - 4*a*c;
		cout << "a=" << a << ",b=" << b << ",c=" << c << ",d=" << d << endl;
		double T[4];
		if(a < EPS && a > -EPS)
		{
			T[1] = -c / b;
			if(t[i-1] + T[1] - t[i-1] > -EPS && t[i-1] + T[1] - t[i] < EPS)
				done = 1;
		}
		else if(d >= -EPS)
		{
			if(d < 0) d = 0;
			T[3] = (-b+sqrt(d))/(2*a);
			if(t[i-1] + T[3] - t[i-1] > -EPS && t[i-1] + T[3] - t[i] < EPS)
				done = 3;
			T[2] = (-b-sqrt(d))/(2*a);
			if(t[i-1] + T[2] - t[i-1] > -EPS && t[i-1] + T[2] - t[i] < EPS)
				done = 2;
		}
		if(done)
		{
			double X = (1-T[done]/(t[i]-t[i-1]))*x[i-1] + T[done]/(t[i]-t[i-1])*x[i];
			double Y = (1-T[done]/(t[i]-t[i-1]))*y[i-1] + T[done]/(t[i]-t[i-1])*y[i];
			double Z = (1-T[done]/(t[i]-t[i-1]))*z[i-1] + T[done]/(t[i]-t[i-1])*z[i];
			printf("YES\n%.10f\n%.10f %.10f %.10f\n", t[i-1] + T[done], X, Y, Z);
			break;
		}
	}
	if(!done)
		cout << "NO" << endl;
	
	return 0;
}
