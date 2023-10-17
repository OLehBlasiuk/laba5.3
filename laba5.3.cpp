#include <iostream>
#include <cmath>
using namespace std;
double h(const double x);
int main()
{
	double rp, rk, z;
	int n;
	cout << "rp = "; cin >> rp;
	cout << "rk = "; cin >> rk;
	cout << "n = "; cin >> n;
	double rg = (rk - rp) / n;
	double r  = rp;
	while (r <= rk)
	{
		z = h(r+1)+pow(h(r*r+1),2)+1 ;
		cout << r  << " " << z << endl;
		r += rg;
	}
	return 0;
}
double h(const double x)
{
	if (abs(x) >= 1 && x==0)
		return (cos(x) + 1) / exp(x);
	else
	{
		double S = 0;
		int n = 0;
		double a = 1;
		S = a;
		do
		{
			n++;
			double R = x * x * 4 / ((2 * n + 2) * (2 * n + 3));
			a *= R;
			S += a;
			S *= 1 / sin(x * x);
		} while (n < 6);
		return S;
	}
}