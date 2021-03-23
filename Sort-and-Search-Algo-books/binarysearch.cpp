#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int binarySearch(vector<int> arr, int target, int start, int end)
{
	//재귀함수에서 언제 탈출하나
	if (start>end) return -1;

	int mid = (start + end) / 2;

	//target의 값이 mid와 같은 경우
	if (arr[mid] == target)
	{
		return mid;
	}
	else if (arr[mid] > target)
	{
		binarySearch(arr, target, start, mid - 1);
	}
	else
	{
		binarySearch(arr, target, mid + 1, end);
	}
}

int main()
{
	time_t start_time = time(0);
	//전체 input개수와 찾으려는 target값 입력
	int n, target;
	cin >> n >> target;

	vector<int> arr(n,0);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int answer = binarySearch(arr, target, 0, n - 1);

	//존재하지 않을 때
	if (answer == -1)
	{
		cout << "배열안에 target이 존재하지 않는다" << endl;
	}

	else
	{
		cout << "배열안에서 이 target의 위치는 : " << answer << endl;
	}

	time_t end_time = time(0);

	cout << "time : " << end_time - start_time << endl;
	return 0;
}