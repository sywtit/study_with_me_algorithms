#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
using namespace std;

int main()
{
	//시간 재기
	time_t start_time = time(0);

	//입력 받기
	string input;
	cin >> input;

	//오른쪽//왼쪽으로 두칸 이동 후 아래//위로로 한칸 이동
	//아래로//위로 두칸 이동 후 오른쪽//왼쪽으로 이동
	int dx[] = { -2,-2,-1,-1,1,1,2,2 };
	int dy[] = { 1,-1,2,-2,2,-2,1,-1 };
	//전체 8

	int loc1 = input.at(0) - 'a' +1;
	int loc2 = input.at(1) - '0';

	int loc1_end = 0;
	int loc2_end = 0;
	int count = 0;

	for (int i = 0; i < 8; i++)
	{
		loc1_end = loc1 + dx[i];
		loc2_end = loc2 + dy[i];
		if (loc1_end >= 1 && loc1_end <= 8 && loc2_end >= 1 && loc2_end <= 8)
			count++;

	}
	cout << count << endl;

	time_t end_time = time(0);
	cout << "time :" << end_time - start_time << endl;

	return 0;

}