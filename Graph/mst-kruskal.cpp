/*
* Minimum Spanning Tree
*
* - MST �� Ʈ���̴� Cycle�� �����ϸ� �ȵȴ�.
* - Ʈ������ ���(Path)�� "Unique" �ϴ�. �̷� ���� Ʈ���� ����� ���� N �� ��, ������ = N - 1 �� �ȴ�.
*	�ݴ�� "����� ���� N �� ��, ������ = N - 1 �� �׷���" �� Ʈ���̴�.
* - �ð� ���⵵ -> O(ElogE)  ,  E: ���� ��
* - �ּ� ����� ����������, ��δ� ������ ������ �� �ִ�.
*
* Kruskal �� ���� ��� ������
* Prim �� ��� ������
*
* �׸� : https://blog.naver.com/kks227/220799105543
* ���� : https://www.acmicpc.net/problem/1922
*/

#include <iostream>
#include <queue>

#define EDGE 7
#define NODE 5

using namespace std;

// 0. �غ�
char parent[200];

struct Edge {
	int v1, v2, cost;
};
bool operator< (Edge a, Edge b) { // min heap
	return a.cost > b.cost;
}

// 1. Union-Find�� �����Ѵ�.
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

// 2. MST ����
void kruskal() {
	priority_queue<Edge> pq;
	int edge_cnt = 0;
	int acc = 0;

	for (int i = 0; i < EDGE; i++) {
		pq.push({ edge[i].v1, edge[i].v2, edge[i].cost });
	}

	// Spanning Tree Ž�� �� �ּ� ��� ���
	while (1) {
		if (edge_cnt == NODE - 1) break; // Ʈ���� �ϼ� �Ǿ���.

		Edge e = pq.top();
		pq.pop();

		if (find(e.v1) == find(e.v2)) continue; // Cycle Ȥ�� �̹� Ʈ���� ����� ���, ���� ������ ��� ������ �ʼ��̴�.

		unite(e.v1, e.v2); // �׷��� ������ Ʈ���� ���� �ϰ� ����� ����Ѵ�.
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

// cycle ������ ���� ��� ������ �ʼ���.
char find(char now) {
	if (parent[now] == now) return now;
	return parent[now] = find(parent[now]); // ��� -> ��� ���� -> ���� ; short code
}

void unite(char a, char b) {
	parent[find(b)] = find(a);
}