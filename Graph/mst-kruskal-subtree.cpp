/*
* 그림 : https://blog.naver.com/kks227/220799105543
* 예제 : https://www.acmicpc.net/problem/1922
* 
* 이미 연결된 간선들이 존재할 때, 남은 노드를 모두 연결해야 하는데 드는 최소비용.
* acc == 3
*/
#include <iostream>
#include <queue>

#define EDGE 7
#define NODE 5

using namespace std;

char parent[200];

struct Edge {
	int v1, v2, cost;
};
bool operator< (Edge a, Edge b) { // min heap
	return a.cost > b.cost;
}

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

void makeCycle() {
	// Cycle 생성
	unite('b', 'e');
	unite('e', 'c');
	unite('c', 'b');
}

void kruskal() {
	priority_queue<Edge> pq;
	int edge_cnt = 0;
	int acc = 0;

	for (int i = 0; i < EDGE; i++) {
		pq.push({ edge[i].v1, edge[i].v2, edge[i].cost });
	}

	// 트리의 완성으로 종료 시키지 않아야 한다. 여기서는 2번으로 구현한다.
	// 1. 문제에 따라 간선의 개수, 조건 등을 정확히 하여 if문으로 종료 시킨다. -> 효율적이나, 실수 할 확률이 높음.
	// 2. 지금과 같이 cycle 이 입력 되어 버린 경우는 모든 간선을 탐색하고 종료 시키는 것이 안전하다.
	//	이때, 시간은 pq를 탐색하는 만큼 더 걸림.
	while (!pq.empty()) {
		// if (edge_cnt == NODE - 1) break; // 또는 문제 조건에 맞는 종료문

		Edge e = pq.top();
		pq.pop();

		if (find(e.v1) == find(e.v2)) continue;

		unite(e.v1, e.v2);
		acc += e.cost;
		edge_cnt++;
	}

	cout << acc; // acc == 3
}

int main() {
	init();
	makeCycle();
	kruskal();

	return 0;
}

void init() {
	for (char i = 'a'; i <= 'z'; i++) {
		parent[i] = i;
	}
}

char find(char now) {
	if (parent[now] == now) return now;
	return parent[now] = find(parent[now]);
}

void unite(char a, char b) {
	parent[find(b)] = find(a);
}