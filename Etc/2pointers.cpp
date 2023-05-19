// Unioin Array using 2 Pointers
// https://www.acmicpc.net/problem/11728
// Time Complexity = O(N);

#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v1;
vector<int> v2;
vector<int> u;

// 정렬 된 두 배열 입력
void input() {
	cin >> n >> m;

	int tmp;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v1.push_back(tmp);
	}
	for (int j = 0; j < m; j++) {
		cin >> tmp;
		v2.push_back(tmp);
	}
}

void print() {
	int sz = u.size();
	for (int i = 0; i < sz; i++) {
		cout << u[i] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	input();

	int p1 = 0, p2 = 0; // 벡터가 아닌 배열일 경우 결과 배열의 idx 가 하나 더 필요
	while (1) {
		if (p1 >= n || p2 >= m) break; // 정상 구간 내에

		if (v1[p1] == v2[p2]) {
			u.push_back(v1[p1]);
			u.push_back(v2[p2]);
			p1++;
			p2++;
		}
		else if (v1[p1] < v2[p2]) {
			u.push_back(v1[p1++]);
		}
		else if (v1[p1] > v2[p2]) {
			u.push_back(v2[p2++]);
		}
	}

	// 남았을 경우
	while (1) {
		if (p1 >= n) break;
		u.push_back(v1[p1++]);
	}

	while (1) {
		if (p2 >= m) break;
		u.push_back(v2[p2++]);
	}

	print();

	return 0;
}