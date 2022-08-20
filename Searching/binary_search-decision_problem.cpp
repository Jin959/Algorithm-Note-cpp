// 결정 문제의 경계를 찾는 경우, 예제 https://www.acmicpc.net/problem/2805

/*
mid == '1'이면 오른쪽을, mid == '0'이면 왼쪽을 탐색한다.
lb == rb 일 때의 mid가 마지막 '1'을 가리킨다. -> 그렇지 않다. 잘못 된 생각이다.
11110000    ->     0000    ->    00    ->    0    : lb = rb = 4
11100000    ->     111     ->    1                : lb = rb = 2
와 같이 lb = mid + 1, rb = mid - 1로 갱신하면 매번 lb == rb가 되는 곳이 달라진다.



따라서 한 쪽을 그냥 mid로 한다.그러면 반환 값이 정해진다.

1. rb = mid로 할 경우, 오른쪽(upper_bound, right_bound)을 반환한다. -> 항상 0으로 시작되는 위치를 반환한다.

11110000, mid = 3   ->   0000, mid = 5   ->   00, mid = 6   ->   0   : lb = rb = 4
11100000, mid = 3   ->   1110, mid = 1   ->   110, mid = 2  ->   10, mid = 2   ->   0   : lb = rb = 3

2. lb = mid로 할 경우, 왼쪽(lower_bound, left_bound)을 반환한다. -> 무한반복이 일어난다.
무한 반복되는 이유는 mid = (lb + rb) / 2가 왼쪽을 반환 하기 때문이다.

11110000, mid = 3   ->   10000, mid = 5  ->   10, mid = 3   ->   10, mid = 3   -> 무한반복

이 경우 lb를 반환 시키려면, mid = (lb + rb) / 2 + 1로 mid 갱신이 오른쪽을 반환하도록 해야한다.



따라서, mid 갱신이 왼쪽을 반환하면(mid = (lb + rb) / 2), 구간 갱신에서는 오른쪽(rb = mid)을 반환해야한다.
반대로, mid 갱신이 오른쪽을 반환하면(mid = (lb + rb) / 2 + 1), 구간 갱신은 왼쪽(lb = mid)을 반환해야한다.




다른 보편적인 방법은 아래 링크
https://www.acmicpc.net/blog/view/109
 */

int binarySearch()
{
	char arr[8 + 1] = "11110000";
	int lb = 0, rb = 9;
	int mid;

	while (1)
	{
		// 0. mid 갱신
		mid = (lb + rb) / 2;

		// 1. 실패
		if (lb > rb) return -1; // 실패 sign

		// 2. 성공
		// 항상 0으로 시작되는 위치를 반환한다. 오른쪽(upper_bound, right_bound)을 반환한다.
		if (lb == rb) return mid;

		// 3. 구간 갱신
		// arr[mid] == '1'이면 오른쪽을, arr[mid] == '0'이면 왼쪽을 탐색한다.
		if (arr[mid] == '1')
		{
			lb = mid + 1;
		}
		else
		{
			rb = mid;
		}
	}

	return -2;
}