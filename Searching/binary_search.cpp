// ���� : ���ĵ� arr���� �Ѵ�.
/*
���� �ش�Ǵ� ���� ã�� �����̹Ƿ� mid = r - 1, mid = l + 1�� Cross Over ���� �����Ų��.
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

		// 1. ����
		if (rb < lb)
		{
			cout << "target doesn't exist" << endl;
			break;
		}

		// 2. ����
		if (arr[mid] == target)
		{
			cout << "target idx : " << mid << endl;
			break;
		}

		// 3. ���� ����
		if (arr[mid] < target)      // target�� �����ʿ� ������ �������� Ž��
		{
			lb = mid + 1;
		}
		else                        // target�� ���ʿ� ������ ������ Ž��
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