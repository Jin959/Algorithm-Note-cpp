// [**결정 문제의 경계를 찾는 경우, "lb == rb" 일때 반복 종료 시킨다.**]
// 예제 https://www.acmicpc.net/problem/2805

// 결정 문제는 배열에서 원하는 값을 찾는 이분탐색과 완전히 같지 않다. "경계"를 찾는 문제이기 때문이다.
// 즉, lb, rb가 cross over 될때 종료 되는 것이 아니다.

/*

mid == '1'이면 mid의 오른쪽을, mid == '0'이면 mid의 왼쪽을 탐색한다. 그러나 그 경계를 집어내는 게 목표이다.

*** lb = mid + 1, rb = mid - 1로 갱신하는 경우
lb == rb 일 때의 mid가 마지막 '1'을 가리킨다. -> 그렇지 않다. 잘못 된 생각이다.
11110000    ->     0000    ->    00    ->    0    : lb = rb = 4
11100000    ->     111     ->    1                : lb = rb = 2
와 같이 lb = mid + 1, rb = mid - 1로 갱신하면 "매번 lb == rb가 되는 곳이 달라진다."



*** 한 쪽을 그냥 mid로 한다.그러면 반환 값이 정해진다.

1. rb = mid, lb = mid + 1 로 할 경우, 오른쪽(upper_bound, right_bound)을 반환한다.
-> 항상 0으로 시작되는 위치를 반환한다.

11110000, mid = 3  ->  0000, mid = 5  ->  00, mid = 4  ->  0  : lb = rb = 4
11100000, mid = 3  ->  1110, mid = 1  ->  10, mid = 2  ->  0  : lb = rb = 3

2. lb = mid, rb = mid - 1 로 할 경우, 왼쪽(lower_bound, left_bound)을 반환한다.
-> 무한반복이 일어난다.
무한 반복되는 이유는 mid = (lb + rb) / 2가 "int"형의 "/" 연산 때문에 배열을 절반 접었을 때의 "왼쪽"을 반환 하기 때문이다.

11110000, mid = 3  ->  10000, mid = 5  ->  10, mid = 3  ->  10, mid = 3  -> 무한반복

lb = mid를 사용하면서 반복이 일어나지 않도록 하려면, mid = ((lb + rb) / 2) + 1로 mid 갱신이 오른쪽을 반환하도록 해야한다.



*** 따라서, mid 갱신이 "왼쪽"을 반환하면(mid = (lb + rb) / 2), 구간 갱신에서는 오른쪽(rb = mid)을 반환해야한다.
반대로, mid 갱신이 오른쪽을 반환하면(mid = (lb + rb) / 2 + 1), 구간 갱신은 왼쪽(lb = mid)을 반환해야한다.

그런데 (mid = (lb + rb) / 2 + 1) 는 복잡하므로

mid 갱신이 "왼쪽"을 반환(mid = (lb + rb) / 2)하도록 하고, 결과를 리턴할 때 mid -1 을 리턴 하면 된다.

이도저도 복잡하면 하던데로 배열에서 원소를 찾는 binary_search를 구현하고 성공 조건을
if (arr[mid] == '1' && arr[mid + 1] == '0') {}
로 정확히 명시한다.


다른 보편적인 방법은 아래 링크
https://www.acmicpc.net/blog/view/109
 */
#include <iostream>
using namespace std;

char arr[8 + 1] = "11110000";

int binarySearch()
{
	int lb = 0, rb = sizeof(arr)/sizeof(*arr) - 2; // 문자열의 "\n" 때문에 -2
	int mid = -2;

	while (1)
	{
		// 0. mid 갱신
		mid = (lb + rb) / 2;

		// 1. 실패 : 사실상 값이 1, 0 두개 밖에 존재하지 않으므로 결정 문제에서는 원소를 찾는 이분탐색과 다르게 필요없다.
		//if (lb > rb) return -1; // 실패 sign

		// 2. 성공
		// 항상 0으로 시작되는 위치를 반환한다. 오른쪽(upper_bound, right_bound)을 반환한다.
		if (lb == rb) return mid; // mid == 4

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

	return mid;
}

int main() {

	int ret = binarySearch();

	if (ret == -1)
	{
		cout << "target doesn't exist" << endl;
	}
	else {
		cout << "target idx : " << ret << endl;
	}

	return 0;
}