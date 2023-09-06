// https://www.jungol.co.kr/problem/2000

// ������ ������ ���� ������谡 �ƴ� �� �ֱ� ������ Ž���� ���� ������ �������� �ʴ´�.

#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 10
#define MAXW 64000

using namespace std;

int n;
int coin[MAXN];
int DT[MAXW + 1];
int target;	// ���ְ� ���� �ܵ� �׼�

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
		DT[coin[i]] = 1;			// "���� ������ �ش��ϴ� �ݾ�"�� �ּ� ���� ������ 1�� �̴�.
		for (int j = (coin[i] + 1); j <= target; j++) {
			DT[j] = min(DT[j - coin[i]] + 1, DT[j]);
		}
	}

	if (DT[target] == 0x7f7f7f7f) cout << "impossible";
	else cout << DT[target];

	return 0;
}