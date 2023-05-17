// ���� : ���ĵ� arr���� �Ѵ�.
/*
���� ������ ��踦 ã�� ���, "lb == rb" �϶� ���� ��Ų��.
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
		// 0. mid ����
		int mid = (lb + rb) / 2;

		// ���� ���̽��� �������� ����.

		// 1. ����
		if (lb == rb) // ���� ������ �����Ǹ� lb >=rb
		{
			cout << "begining idx of \'0\' : " << mid << endl;      // begining idx of '0' : 2
			break;
		}

		// 2. ���� ���� : arr[mid] == '1'�̸� ��������, arr[mid] == '0'�̸� ������ Ž���Ѵ�.
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