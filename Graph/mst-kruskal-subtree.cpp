/*
* �׸� : https://blog.naver.com/kks227/220799105543
* ���� : https://www.acmicpc.net/problem/1922
* 
* �̹� ����� �������� ������ ��, ���� ��带 ��� �����ؾ� �ϴµ� ��� �ּҺ��.
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
	// Cycle ����
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

	// Ʈ���� �ϼ����� ���� ��Ű�� �ʾƾ� �Ѵ�. ���⼭�� 2������ �����Ѵ�.
	// 1. ������ ���� ������ ����, ���� ���� ��Ȯ�� �Ͽ� if������ ���� ��Ų��. -> ȿ�����̳�, �Ǽ� �� Ȯ���� ����.
	// 2. ���ݰ� ���� cycle �� �Է� �Ǿ� ���� ���� ��� ������ Ž���ϰ� ���� ��Ű�� ���� �����ϴ�.
	//	�̶�, �ð��� pq�� Ž���ϴ� ��ŭ �� �ɸ�.
	while (!pq.empty()) {
		// if (edge_cnt == NODE - 1) break; // �Ǵ� ���� ���ǿ� �´� ���Ṯ

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