// "�������� �����ε����� 0���� �־����� arr, prefix�� ���̸� 1 ĭ �÷��� �����Ѵ�. "
// 
// arr, prefix sum arr �� idx�� 1���� �����ϴ°� ������ ������ �� �ִ�.
// idx�� 0���� �̸� out of range / seg fault ������ ��ó�ؾ� �ϱ� ������ �ڵ尡 �������.

// https://jungol.co.kr/problem/3136

#include <iostream>
#define MAXN 1'000
#define MAXM 1'000'000
using namespace std;

int arr[MAXN + 1][MAXN + 1];
long long px[MAXN + 1][MAXN + 1]; // prefix sum array
struct Node {
	int y, x;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> arr[y][x];

			px[y][x] = arr[y][x] + px[y - 1][x] + px[y][x - 1] - px[y - 1][x - 1];
		}
	}

	int m;
	cin >> m;
	Node s, e;
	int w, h;
	for (int i = 0; i < m; i++) {
		cin >> s.y >> s.x >> e.y >> e.x;
		h = e.y - (s.y - 1);
		w = e.x - (s.x - 1);

		cout << px[e.y][e.x] - px[e.y - h][e.x] - px[e.y][e.x - w] + px[e.y - h][e.x - w] << '\n';
		//cout << px[e.y][e.x] - px[s.y - 1][e.x] - px[e.y][s.x - 1] + px[s.y - 1][s.x - 1] << '\n';
	}

	return 0;
}