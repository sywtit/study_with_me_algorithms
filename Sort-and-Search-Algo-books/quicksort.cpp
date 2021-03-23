#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

int n = 10;
int arr[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };

//quickSort는 재귀함수로 이용
void quickSort(int* arr, int start, int end)
{
	//원소가 1개 일 때
	if (start >= end) return;

	//pivot 은 제일 첫 번째 수 
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right)
	{
		//피버보다 큰 데이터를 찾을 때까지 반복
		while ((left <= end) && arr[left] <= arr[pivot]) left++;
		//피벗보다 작은 데이터를 찾을 때까지 반복
		while (right > start&& arr[right] >= arr[pivot]) right++;

		//엇갈렸다면 작은 데이터와 피벗을 교체
		if (left > right) swap(arr[right], arr[pivot]);
		else swap(arr[right], arr[left]);
	}

	//왼쪽과 오른쪽 배열을 sort하기 시작
	quickSort(arr, start, right-1);
	quickSort(arr, right + 1, end);
}

int main_1()
{
	time_t start_time = time(0);
	//quickSort(arr,0,n-1);
	//입력값으로 전체 array와 start,end값을 받아옴
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << ' ';
	}
	time_t end_time = time(0);

	cout << "time : " << end_time - start_time << endl;

	return 0;
}