/*
* Dijkstra �湮 ��� ���
* https://jungol.co.kr/problem/3118
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
int parent[MAXN];			// parent[node] = node �湮 ������ �ִ� �θ� ���
Node goal;

/*
* �湮 Ʈ�� ���� ��ȸ
* �������� ��� N ���� ��� 1 ���� �Ųٷ� Ÿ�� ����.
* union-find �� find ó�� init() �ѵ�, parent[now] == now �� ��찡 ���� ������ �� �� ����.
* Ž�� �� ��� ������ ������ ����.
*/
void findParent(int now) {
	if (now == start.vertex) {
		cout << now + 1 << ' '; // ���� 1����
		return;
	}

	findParent(parent[now]);
	cout << now + 1 << ' ';
	return;
}

void init() {
	cin >> n >> m;
	int from, to, cost;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		adj[from - 1].push_back({ to - 1, cost });
	}

	fill(dist, dist + n, INF);
	memset(visited, 0, sizeof(visited));

	goal.vertex = n - 1;
}

int dijkstra() {

	priority_queue<Node> pq;
	pq.push(start);

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		if (visited[now.vertex]) continue;
		visited[now.vertex] = 1;

		for (Edge next : adj[now.vertex]) {
			if (now.acc + next.cost < dist[next.vertex]) {
				dist[next.vertex] = now.acc + next.cost;
				pq.push({ next.vertex, dist[next.vertex] });

				parent[next.vertex] = now.vertex;		// �߿� : �ּ� ��θ� �߰��� ��, �θ� ��� ���
			}
		}
	}

	return dist[n - 1];
}

int main() {
	init();
	goal.acc = dijkstra();
	cout << goal.acc << '\n';
	findParent(goal.vertex);		// ������ ���� Ʈ�� ���� Ž��
	return 0;
}