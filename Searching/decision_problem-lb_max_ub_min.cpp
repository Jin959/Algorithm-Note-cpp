// ���� : ���ĵ� arr���� �Ѵ�.
/*
���� ������ ������ �ִ밪, ������ �ּҰ��� ã�� ���, "lb + 1 == ub" �϶� ���� ��Ų��.
*/

#include <iostream>
#define MAXN 8
using namespace std;

char arr[MAXN + 1] = "TTTTTFFF";

// �������� �ٸ���.
char decisionFunc(int mid) {
	return arr[mid];
}

// lower bound �� �ִ밪�� ã�´�.
int lowerBnd()
{
	int lb = 0, ub = MAXN - 1;
	int mid;

	while (1)
	{
		mid = (lb + ub) / 2;

		if (lb + 1 == ub) break; // lb�� ub�� ��迡�� �� ���� �� ������ ����

		char decision = decisionFunc(mid);

		if (decision == 'T')
		{
			lb = mid;
		}
		else
		{
			ub = mid;
		}
	}

	return lb;
}

// upper bound�� �ּҰ��� ã�´�.
int upperBnd() {
	int lb = 0, ub = MAXN - 1;
	int mid;

	while (1)
	{
		mid = (lb + ub) / 2;

		if (lb + 1 == ub) break; // lb�� ub�� ��迡�� �� ���� �� ������ ����

		char decision = decisionFunc(mid);

		if (decision == 'F')
		{
			ub = mid;
		}
		else
		{
			lb = mid;
		}
	}

	return ub;
}

int main() {
	cout << "max lower bound idx : " << lowerBnd() << endl; // max lower bound idx : 4
	cout << "min upper bound idx : " << upperBnd() << endl; // min upper bound idx : 5

	return 0;
}