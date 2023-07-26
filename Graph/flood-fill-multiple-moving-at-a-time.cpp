// https://school.programmers.co.kr/learn/courses/30/lessons/169199

// 장애물을 만나기 전까지 계속 이동하며 장애물을 만나 멈출때까지가 1회 이동이다.

#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define MAXN 100

using namespace std;

// R에서 시작, G는 목적지, D는 장애물
vector<string> MAP = { "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." }; // 7
//vector<string> MAP = { ".D.R", "....", ".G..", "...D" };                        // -1
bool visited[MAXN][MAXN];
int dist[MAXN][MAXN];
int cnt;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

struct Node {
    int y, x;
};

Node start, goal;

void init() {
    int tmp = 0;
    for (int i = 0; i < MAP.size(); i++) {
        for (int j = 0; j < MAP[0].size(); j++) {
            if (MAP[i][j] == 'R') {
                start = { i, j };
                tmp++;
            }
            if (MAP[i][j] == 'G') {
                goal = { i, j };
                tmp++;
            }
            if (tmp == 2) return;
        }
    }
}

bool isOut(Node n) {
    return (n.y < 0 || n.y >= MAP.size() || n.x < 0 || n.x >= MAP[0].size());
}

void bfs() {
    queue<Node> q;
    q.push(start);
    visited[start.y][start.x] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (MAP[now.y][now.x] == 'G') return;

        for (int i = 0; i < 4; i++) {
            Node nxt = { now.y + dy[i], now.x + dx[i] };
            if (isOut(nxt)) continue;
            if (MAP[nxt.y][nxt.x] == 'D') continue;

            while (1) {
                nxt.y += dy[i];
                nxt.x += dx[i];
                if (isOut(nxt) || MAP[nxt.y][nxt.x] == 'D') {
                    nxt.y -= dy[i];
                    nxt.x -= dx[i];
                    break;
                }
            }

            if (visited[nxt.y][nxt.x]) continue;

            visited[nxt.y][nxt.x] = true;
            dist[nxt.y][nxt.x] = dist[now.y][now.x] + 1;
            q.push(nxt);
        }
    }
}


int main() {
    init();
    bfs();

    if (!visited[goal.y][goal.x]) {
        cout << -1;
        return 0;
    }
    cout << dist[goal.y][goal.x];
    return 0;
}