/*
* Dijkstra
*
* https://jungol.co.kr/problem/3118
*
* 음의 가중치가 존재하지 않을 때, SSPS
* start : Node 1
* goal : Node N
* 
* 시간 복잡도 : O(ElogV)
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

void init() {
	cin >> n >> m;
	int from, to, cost;
	for (int i = 0; i < m; i++) {
		cin >> from >> to >> cost;
		adj[from - 1].push_back({ to - 1, cost });
	}

	// 0. 초기화
	fill(dist, dist + n, INF);
	memset(visited, 0, sizeof(visited));
}

int dijkstra() {

	priority_queue<Node> pq;
	// 0. 시작점 세팅
	pq.push(start);
	dist[start.vertex] = 0;		// 주의 : 자주 잊음.

	while (!pq.empty()) {
		// 1. 노드를 하나 택한다.
		Node now = pq.top();
		pq.pop();

		// 2. 방문처리
		if (visited[now.vertex]) continue;
		visited[now.vertex] = 1;

		// 3. 우선순위 탐색
		for (Edge next : adj[now.vertex]) {
			if (now.acc + next.cost < dist[next.vertex]) { // 중요
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