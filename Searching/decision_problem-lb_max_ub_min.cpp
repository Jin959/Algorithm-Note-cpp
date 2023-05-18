// 주의 : 정렬된 arr여야 한다.
/*
결정 문제의 하한의 최대값, 상한의 최소값을 찾는 경우, "lb + 1 == ub" 일때 종료 시킨다.
*/

#include <iostream>
#define MAXN 8
using namespace std;

char arr[MAXN + 1] = "TTTTTFFF";

// 문제마다 다르다.
char decisionFunc(int mid) {
	return arr[mid];
}

// lower bound 의 최대값을 찾는다.
int lowerBnd()
{
	int lb = 0, ub = MAXN - 1;
	int mid;

	while (1)
	{
		mid = (lb + ub) / 2;

		if (lb + 1 == ub) break; // lb와 ub가 경계에서 딱 만날 때 까지만 진행

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

// upper bound의 최소값을 찾는다.
int upperBnd() {
	int lb = 0, ub = MAXN - 1;
	int mid;

	while (1)
	{
		mid = (lb + ub) / 2;

		if (lb + 1 == ub) break; // lb와 ub가 경계에서 딱 만날 때 까지만 진행

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