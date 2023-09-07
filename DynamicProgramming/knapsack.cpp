// https://www.jungol.co.kr/problem/1077

#include <iostream>
#include <algorithm>

#define MAXN 1000	// ����, item�� ����
#define MAXW 10000	// �賶�� �뷮

using namespace std;

struct Item {
	int weight, value;
};

int n, w;
Item item[MAXN];
int DT[MAXW + 1];

void input() {
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> item[i].weight >> item[i].value;
	}
}

int main() {
	input();

	for (int i = 0; i < n; i++) {
		for (int j = item[i].weight; j <= w; j++) {
			DT[j] = max(DT[j - item[i].weight] + item[i].value, DT[j]);
		}
	}

	cout << DT[w];

	return 0;
}