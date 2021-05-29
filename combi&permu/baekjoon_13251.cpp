#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

double sol;
int num[50];
int main() {
	//조약돌의 색상
	int m;
	int total = 0;
	int k;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> num[i];
		total += num[i];
	}

	cin >> k;
	for (int i = 0; i < m; i++)
	{
		double temp = 1.0;
		if (k > num[i])	continue;
		for (int j = 0; j < k; j++)
		{
			temp *= (double)(num[i] - j) / (total - j);
		}
		sol += temp;
	}
	cout << fixed;
	cout.precision(15);
	cout << sol;

	
}