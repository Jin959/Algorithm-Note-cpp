/*
* Dijkstra
*
* https://jungol.co.kr/problem/3118
*
* ���� ����ġ�� �������� ���� ��, SSPS
* start : Node 1
* goal : Node N
* 
* �ð� ���⵵ : O(ElogV)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAXN 100000 // tip : C/C++ int�� ���� �迭 �ִ����
#define INF 21e8

using namespace std;


struct Node {
	int vertex, acc;

	// min heap
	bool operator< (const Node node) const { // const �޼���
		return this->acc > node.acc;
	}
} start{ 0, 0 };

struct Edge {
	int vertex, cost;
};


int n, m;
int visited[MAXN];
int dist[MAXN];
vector<Edge> adj[MAXN];

void init() {
	cin >> n >> m;
	int from, to, cost;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		adj[from - 1].push_back({ to - 1, cost });
	}

	// 0. �ʱ�ȭ
	fill(dist, dist + n, INF);
	memset(visited, 0, sizeof(visited));
}

int dijkstra() {

	priority_queue<Node> pq;
	// 0. ������ ����
	pq.push(start);
	dist[start.vertex] = 0;		// ���� : ���� ����.

	while (!pq.empty()) {
		// 1. ��带 �ϳ� ���Ѵ�.
		Node now = pq.top();
		pq.pop();

		// 2. �湮ó��
		if (visited[now.vertex]) continue;
		visited[now.vertex] = 1;

		// 3. �켱���� Ž��
		for (Edge next : adj[now.vertex]) {
			if (now.acc + next.cost < dist[next.vertex]) { // �߿�
				dist[next.vertex] = now.acc + next.cost;
				pq.push({ next.vertex, dist[next.vertex] });
			}
		}
	}

	return dist[n - 1];
}

int main() {
	init();
	cout << dijkstra();
	return 0;
}