/*
* Minimum Spanning Tree
*
* - MST 는 트리이다 Cycle이 존재하면 안된다.
* - 트리에서 경로(Path)는 "Unique" 하다. 이로 인해 트리는 노드의 수가 N 일 때, 간선수 = N - 1 이 된다.
*	반대로 "노드의 수가 N 일 때, 간선수 = N - 1 인 그래프" 는 트리이다.
* - 시간 복잡도 -> O(ElogE)  ,  E: 간선 수
* - 최소 비용은 유일하지만, 경로는 여러개 존재할 수 있다.
*
* Kruskal 은 간선 비용 순으로
* Prim 은 노드 순으로
*
* 그림 : https://blog.naver.com/kks227/220799105543
* 예제 : https://www.acmicpc.net/problem/1922
*/

#include <iostream>
#include <queue>

#define EDGE 7
#define NODE 5

using namespace std;

// 0. 준비물
char parent[200];

struct Edge {
	int v1, v2, cost;
};
bool operator< (Edge a, Edge b) { // min heap
	return a.cost > b.cost;
}

// 1. Union-Find를 구현한다.
void init();
char find(char now);
void unite(char a, char b);

Edge edge[EDGE] = {
	{'a', 'e', 1},
	{'c', 'd', 2},
	{'a', 'b', 3},
	{'b', 'e', 4},
	{'b', 'c', 5},
	{'c', 'e', 6},
	{'d', 'e', 7}
};

// 2. MST 구현
void kruskal() {
	priority_queue<Edge> pq;
	int edge_cnt = 0;
	int acc = 0;

	for (int i = 0; i < EDGE; i++) {
		pq.push({ edge[i].v1, edge[i].v2, edge[i].cost });
	}

	// Spanning Tree 탐색 및 최소 비용 기록
	while (1) {
		if (edge_cnt == NODE - 1) break; // 트리가 완성 되었다.

		Edge e = pq.top();
		pq.pop();

		if (find(e.v1) == find(e.v2)) continue; // Cycle 혹은 이미 트리에 연결된 노드, 여기 때문에 경로 압축이 필수이다.

		unite(e.v1, e.v2); // 그렇지 않으면 트리에 연결 하고 비용을 기록한다.
		acc += e.cost;
		edge_cnt++;
	}

	cout << acc; // acc == 11
}

int main() {
	init();
	kruskal();

	return 0;
}


void init() {
	for (char i = 'a'; i <= 'z'; i++) {
		parent[i] = i;
	}
}

// cycle 검출을 위해 경로 압축이 필수다.
char find(char now) {
	if (parent[now] == now) return now;
	return parent[now] = find(parent[now]); // 재귀 -> 경로 압축 -> 리턴 ; short code
}

void unite(char a, char b) {
	parent[find(b)] = find(a);
}