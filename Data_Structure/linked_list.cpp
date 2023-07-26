/*
Linked List �� ����ϴ� ����
���Ḯ��Ʈ : �յ� �߰� ��� ���� ���԰� ������ O(1) / ��ȸ�� ���������� �ϹǷ� O(N)
�迭 : �߰��� ������ ��� �ϳ��� �ڷ� �о� �̵��Ͽ� O(N) / ��ȸ�� O(1)
*/

// ȭ��ǥ ������ : (*p).n = p->n

/*
���� �Ҵ� : new Ű���带 �̿��Ͽ� ������ ����� ��

Heap������ Runtime�� ���� �� ���Ű� �����ϴ�.

new �� delete

new [�ڷ���](): �޸��� Heap ������ new�� ����Ͽ� �Ҵ��ϰ� �� �ּҸ� ��ȯ�Ѵ�.
delete [�����Ҵ��� �ּ�] : �����Ҵ��� �� ���� release�Ѵ�.
*/

/*
static Ű���� : https://modoocode.com/197
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