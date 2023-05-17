// 주의 : 정렬된 arr여야 한다.
/*
결정 문제의 경계를 찾는 경우, "lb == rb" 일때 종료 시킨다.
*/
#include <iostream>
using namespace std;

int n = 5;
int arr[]{ 1, 1, 0, 0, 0 };

void binarySearch(int arr[])
{
	int lb = 0;
	int rb = n - 1;

	while (1)
	{
		// 0. mid 갱신
		int mid = (lb + rb) / 2;

		// 실패 케이스는 존재하지 않음.

		// 1. 성공
		if (lb == rb) // 무한 루프가 걱정되면 lb >=rb
		{
			cout << "begining idx of \'0\' : " << mid << endl;      // begining idx of '0' : 2
			break;
		}

		// 2. 구간 갱신 : arr[mid] == '1'이면 오른쪽을, arr[mid] == '0'이면 왼쪽을 탐색한다.
		if (arr[mid] == 1)
		{
			lb = mid + 1;
		}
		else
		{
			rb = mid;
		}
	}

	return;
}

int main()
{

	binarySearch(arr);

	return 0;
}