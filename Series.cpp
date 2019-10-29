#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	double x, E;
	cin >> x >> E;
	while (x == 0 || E <= 0) {
		cin >> x >> E;
	}
	double b;
	vector<double> a = { 0, 1, x };

	for (int i = 3; ; i++) {
		b = 3 + 1 / pow(2, i) * pow(pow(a[i - 1], 2) - x * pow(a[i - 2], 2) - a[i - 3] / x, 2);
		a.push_back(b);
		if (abs(a[i] - a[i - 1]) < E) {
			cout << a[i] << endl;
			cout << i << endl;
			break;
		}
	}
	
}
