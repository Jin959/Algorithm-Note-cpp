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

	static void PushBack(int v);
};

Node* head, * tail;

void Node::PushBack(int v)
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
	Node::PushBack(12);
	Node::PushBack(1);
	Node::PushBack(5);
	Node::PushBack(789);
	Node::PushBack(87);

	Node* n = head;
	while (n != NULL)
	{
		cout << n->val;
		if (n != tail) cout << " -> ";
		n = n->nxt;
	}

	return 0;
}