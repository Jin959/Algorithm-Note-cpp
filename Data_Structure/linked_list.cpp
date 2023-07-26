/*
Linked List 를 사용하는 이유
연결리스트 : 앞뒤 중간 상관 없이 삽입과 삭제가 O(1) / 조회는 순차적으로 하므로 O(N)
배열 : 중간에 삽입할 경우 하나씩 뒤로 밀어 이동하여 O(N) / 조회는 O(1)
*/

// 화살표 연산자 : (*p).n = p->n

/*
동적 할당 : new 키워드를 이용하여 변수를 만드는 것

Heap영역은 Runtime에 변수 및 제거가 가능하다.

new 와 delete

new [자료형](): 메모리의 Heap 영역에 new를 사용하여 할당하고 그 주소를 반환한다.
delete [동적할당한 주소] : 동적할당을 한 곳을 release한다.
*/

/*
static 키워드 : https://modoocode.com/197
*/

#include <iostream>

using namespace std;

struct Node
{
	int val;
	Node* nxt;

	static void pushBack(int v);
};

Node* head, * tail;

void Node::pushBack(int v)
{
	if (head == NULL)
	{
		head = new Node({ v, NULL });
		tail = head;
	}
	else
	{
		tail->nxt = new Node({ v, NULL });
		tail = tail->nxt;
	}
}

int main()
{
	Node::pushBack(12);
	Node::pushBack(1);
	Node::pushBack(5);
	Node::pushBack(789);
	Node::pushBack(87);

	Node* n = head;
	while (n != NULL)
	{
		cout << n->val;
		if (n != tail) cout << " -> ";
		n = n->nxt;
	}
	// 12 -> 1 -> 5 -> 789 -> 87

	return 0;
}