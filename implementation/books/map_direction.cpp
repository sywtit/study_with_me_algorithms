#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<ctime>
using namespace std;

int main()
{
	//time_t start_time = time(0);

	int size = 0;
	string input;
	string token;
	vector<string> movement;
	const char delimiter = ' ';

	cin >> size;
	cin.ignore();
	getline(cin, input);
	stringstream ss(input);

	while (getline(ss, token, delimiter))
	{
		movement.push_back(token);
	}

	//map 과 관련되어서 변수 선언
	int x = 1, y = 1;
	for (int i = 0; i < movement.size(); i++)
	{
		if (movement[i].compare("L") == 0)
		{
			if (x > 1) x -= 1;
		}
		else if (movement[i].compare("R") == 0)
		{
			if (x < size) x += 1;
		}
		else if (movement[i].compare("U") == 0)
		{
			if (y > 1) y -= 1;
		}
		else
		{
			if (y < size) y += 1;
		}
	}

	cout << y << ' ' << x << endl;
	//time_t end_time = time(0);

	//cout << "time : " << end_time - start_time;

	return 0;


}