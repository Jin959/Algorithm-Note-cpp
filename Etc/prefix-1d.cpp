// http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=2417&sca=3080#n

#include <iostream>
#define MAXN 1'000'000
#define MAXM 1'000'000
using namespace std;

int n, m;
int arr[MAXN + 1]; // idx = 1~N
long long prefix[MAXN + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	long long acc = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		acc += arr[i];
		prefix[i] = acc;
	}

	cin >> m;
	int s, e;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;

		long long sum = prefix[e] - prefix[s - 1];
		//long long sum = prefix[e] - prefix[s] + arr[s]; // idx 0부터 시작할 경우

		cout << sum << '\n';
	}

	return 0;
}