#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
using namespace std;

int main()
{
	time_t start_time = time(0);

	int N = 0;
	cin >> N;

	int count = 0;
	int hou = 0, min = 0, sec = 0;
	
	for (int hou = 0; hou < N+1; hou++)
	{
		for (int min = 0; min < 60; min++)
		{
			for (int sec = 0; sec < 60; sec++)
			{
				string houS = to_string(hou);
				string minS = to_string(min);
				string secS = to_string(sec);
				string bigTime = houS + minS + secS;

				if (bigTime.find("3") == string::npos)
				{
					//do nothing
				}
				else
				{
					count++;
				}
			}
		}
	}

	cout << count << endl;
	time_t end_time = time(0);

	cout << "time : " << end_time - start_time << endl;
	//time took 2
	return 0;

}