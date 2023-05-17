// 주의 : 정렬된 arr여야 한다.
/*
단지 해당되는 값을 찾는 문제이므로 mid = r - 1, mid = l + 1로 Cross Over 시켜 종료시킨다.
*/
#include <iostream>
using namespace std;

int n = 5;
int arr[]{ 1, 2, 3, 4, 5 };
int target = 4;

void binarySearch(int arr[], int target)
{
	int lb = 0;
	int rb = n - 1; // n == # of ele

	while (1)
	{
		// 0. mid update
		int mid = (lb + rb) / 2;

		// 1. 실패
		if (rb < lb)
		{
			cout << "target doesn't exist" << endl;
			break;
		}

		// 2. 성공
		if (arr[mid] == target)
		{
			cout << "target idx : " << mid << endl;
			break;
		}

		// 3. 구간 갱신
		if (arr[mid] < target)      // target이 오른쪽에 있으면 오른쪽을 탐색
		{
			lb = mid + 1;
		}
		else                        // target이 왼쪽에 있으면 왼쪽을 탐색
		{
			rb = mid - 1;
		}
	}

	return;
}

int main()
{

	binarySearch(arr, target);

	return 0;
}