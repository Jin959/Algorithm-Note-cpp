// https://www.jungol.co.kr/problem/2000

// 동전의 단위가 서로 배수관계가 아닐 수 있기 때문에 탐용적 선택 조건을 만족하지 않는다.

#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 10
#define MAXW 64000

using namespace std;

int n;
int coin[MAXN];
int DT[MAXW + 1];
int target;	// 내주고 싶은 잔돈 액수

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cin >> target;
}

int main() {
	input();

	memset(DT, 0x7f, sizeof(DT));	// 0x7F (HEX) = 0111 1111(BIN)

	for (int i = 0; i < n; i++) {
		DT[coin[i]] = 1;			// "단위 동전에 해당하는 금액"의 최소 동전 개수는 1개 이다.
		for (int j = (coin[i] + 1); j <= target; j++) {
			DT[j] = min(DT[j - coin[i]] + 1, DT[j]);
		}
	}

	if (DT[target] == 0x7f7f7f7f) cout << "impossible";
	else cout << DT[target];

	return 0;
}