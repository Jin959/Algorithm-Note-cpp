/*
* 같은 그룹에 속해있는지, 다른 그룹인지 확인할 수 있다.
*	- 여기서 부모 자식의 순서는 관계없이 같은 "집합"인지만 판별한다.
* 빠른 속도로 Data 조직의 통합 처리가 가능하다.
*	- 트리의 깊이가 얕을 수록 수행 속도가 더 빠르므로 "경로 압축"을 사용한다.
* MST에서 Cycle 판별에 이용할 수 있다.
* 
* 예제 : https://www.acmicpc.net/problem/1717
*/

#include <iostream>

#define SZ 200

using namespace std;

char parent[SZ]; // 부모를 기록한다.

// 1. 모든 노드의 부모를 자기 자신으로 초기화
void init() {
	for (char i = 'a'; i <= 'z'; i++) {
		parent[i] = i;
	}
}

// 2. find 연산 : 재귀, dfs로 최상위 조상(root node)까지 올라가 return.
char find(char now_node) {
	if (parent[now_node] == now_node) { // base condition
		return now_node;
	}

	char p = find(parent[now_node]); // 최상위 조상까지 올라가고 마지막으로 리턴한다.
	parent[now_node] = p;			 // 경로 압축 : 최상위 조상만 기록하여 비약적 수행시간 축소

	return p;
}

// 3. union 연산 : a <- b 귀속.
// 두 노드의 루트 노드가 다르면, 노드b가 속한 집합을 노드a가 속한 집합에 귀속 시킨다.
void unite(char a, char b) {
	char pa = find(a);
	char pb = find(b);

	if (pa != pb) {
		parent[pb] = pa;
	}
}

int main() {
	init();

	// a-b-c-d
	unite('c', 'd');
	unite('b', 'c');
	unite('a', 'b');

	// f-e
	unite('f', 'e');

	unite('c', 'f'); // 여기서 'c'와 연관된 노드들의 경로 압축이 진행된다.

	for (char i = 'a'; i <= 'f'; i++) {
		cout << "parent[" << i << "] - " << parent[i] << endl;
	}

	return 0;
}