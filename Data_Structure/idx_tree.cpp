//range sum query
/*
For linear search
T(N) = N * (M + K) = 2 * 10^10 ~ 200sec -> O(N(M+K))

For IDT (Bottom-up Approach)
T(N) = (M + K)log(N) < 1sec -> O((M + K)log(N))
*/
/*
���� ���� Ʈ���� ���� = heap�� ����

tree size = 2^x > MAXN
��, data 12���̸�, Leaf ��� ���� = 2^x = 16��, ������ 16�� �ʿ�

�ڵ鸵�� ���� 0�� �����������.
*/


// tree size = 2^x > MAXN, or roughly approximation = MAXN * 4
int tree[MAXN * 4];              // ~ 2^20 > MAXN 
int leaf, n;                     // leaf idx, # of data

void initLeaf()
{
	// �����Ⱚ�� ���� �ʱ�ȭ �� �ϱ�
	for (int i = leaf; i <= 2 * leaf; i++) tree[i] = 0;
	// for (int i = leaf; i <= 2 * leaf; i++) tree[i] = INF;
	for (int i = leaf; i < leaf + n; i++) cin >> tree[i];

	return;
}

void initInternal()
{
	for (int i = leaf - 1; i > 0; i--)
	{
		// sum = left child + right child
		tree[i] = tree[i * 2] + tree[i * 2 + 1]; // rgsum
		// tree[i] = min(tree[i * 2], tree[i*2 + 1]); // rgmin
	}

	return;
}

void update(int idx, int value)
{
	idx += leaf - 1; // idx of a��° �ڷ�
	tree[idx] = value;

	// go to parent node & update
	while (idx > 0)
	{
		idx /= 2;

		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}

	return;
}

int rgSum(int l, int r)
{
	// 0. idx setup
	l += (leaf - 1);
	r += (leaf - 1);
	int ret = 0;
	// int ret = INF; //rgMin

	// left boundary�� right boundary�� ������ �� ���� return �� min value ���� ������ ����.
	while (1)
	{
		if (r < l) break; // ������.

		// 1. �̹� l, r�� �� ���ǿ� �ش�� �� ���� ���Ѵ�.
		if (l % 2 == 1) ret += tree[l];
		if (r % 2 == 0) ret += tree[r];

		// 2. ũ�ν� ����
		l = (l + 1) / 2;
		r = (r - 1) / 2;
	}

	return ret;
}


int main()
{
	// 1. find leaf node idx = # of leaf
	cin >> n;
	for (int leaf = 1; leaf < n; leaf *= 2);

	// 2. init leaf nodes
	initLeaf();

	// 3. init internal nodes
	initInternal();

	// 4. get query and ans

	return 0;
}