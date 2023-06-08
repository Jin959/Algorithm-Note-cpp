/*
* Dijkstra 방문 경로 출력
* https://jungol.co.kr/problem/3118
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define MAXN 100000 // tip : C/C++ int형 기준 배열 최대길이
#define INF 21e8

using namespace std;


struct Node {
	int vertex, acc;

	// min heap
	bool operator< (const Node node) const { // const 메서드
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
int parent[MAXN];			// parent[node] = node 방문 직전에 있던 부모 노드
Node goal;

/*
* 방문 트리 후위 순회
* 목적지인 노드 N 에서 노드 1 까지 거꾸로 타고 들어간다.
* union-find 의 find 처럼 init() 한뒤, parent[now] == now 인 경우가 기저 조건이 될 수 없다.
* 탐색 중 모두 헤집어 버리기 때문.
*/
void findParent(int now) {
	if (now == start.vertex) {
		cout << now + 1 << ' '; // 노드는 1부터
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

				parent[next.vertex] = now.vertex;		// 중요 : 최소 경로를 발견할 때, 부모 노드 기록
			}
		}
	}

	return dist[n - 1];
}

int main() {
	init();
	goal.acc = dijkstra();
	cout << goal.acc << '\n';
	findParent(goal.vertex);		// 목적지 부터 트리 후위 탐색
	return 0;
}