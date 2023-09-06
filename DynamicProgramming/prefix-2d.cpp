// "문제에서 시작인덱스가 0으로 주어져도 arr, prefix의 길이를 1 칸 늘려서 구현한다. "
// 
// arr, prefix sum arr 의 idx를 1부터 시작하는게 빠르게 구현할 수 있다.
// idx가 0부터 이면 out of range / seg fault 에러에 대처해야 하기 때문에 코드가 길어진다.

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