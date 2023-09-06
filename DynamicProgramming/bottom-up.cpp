// https://www.jungol.co.kr/problem/3522 

/*
* Bottom-up
*
* Bottom-up 이 직관적인 경우가 있다.
* 숫자카드 문제가 그랬다.
* https://www.acmicpc.net/problem/2591
* Top-down으로는 분기 처리가 복잡해지고 구현도 오래걸렸다.
*/

#include <iostream>

#define MAXN 100000

using namespace std;

int DT[MAXN + 1];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		// 초항
		if (i == 1 || i == 2) {
			DT[i] = 1;
			continue;
		}

		// 점화식
		DT[i] = (DT[i - 1] + DT[i - 2]) % (int)(10e8 + 7);
	}

	cout << DT[n] << endl;

	return 0;
}
