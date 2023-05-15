/*
* ���� �׷쿡 �����ִ���, �ٸ� �׷����� Ȯ���� �� �ִ�.
*	- ���⼭ �θ� �ڽ��� ������ ������� ���� "����"������ �Ǻ��Ѵ�.
* ���� �ӵ��� Data ������ ���� ó���� �����ϴ�.
*	- Ʈ���� ���̰� ���� ���� ���� �ӵ��� �� �����Ƿ� "��� ����"�� ����Ѵ�.
* MST���� Cycle �Ǻ��� �̿��� �� �ִ�.
* 
* ���� : https://www.acmicpc.net/problem/1717
*/

#include <iostream>

#define SZ 200

using namespace std;

char parent[SZ]; // �θ� ����Ѵ�.

// 1. ��� ����� �θ� �ڱ� �ڽ����� �ʱ�ȭ
void init() {
	for (char i = 'a'; i <= 'z'; i++) {
		parent[i] = i;
	}
}

// 2. find ���� : ���, dfs�� �ֻ��� ����(root node)���� �ö� return.
char find(char now_node) {
	if (parent[now_node] == now_node) { // base condition
		return now_node;
	}

	char p = find(parent[now_node]); // �ֻ��� ������� �ö󰡰� ���������� �����Ѵ�.
	parent[now_node] = p;			 // ��� ���� : �ֻ��� ���� ����Ͽ� ����� ����ð� ���

	return p;
}

// 3. union ���� : a <- b �ͼ�.
// �� ����� ��Ʈ ��尡 �ٸ���, ���b�� ���� ������ ���a�� ���� ���տ� �ͼ� ��Ų��.
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

	unite('c', 'f'); // ���⼭ 'c'�� ������ ������ ��� ������ ����ȴ�.

	for (char i = 'a'; i <= 'f'; i++) {
		cout << "parent[" << i << "] - " << parent[i] << endl;
	}

	return 0;
}