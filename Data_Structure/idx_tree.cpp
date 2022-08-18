//range sum query
/*
For linear search
T(N) = N * (M + K) = 2 * 10^10 ~ 200sec -> O(N(M+K))

For IDT (Bottom-up Approach)
T(N) = (M + K)log(N) < 1sec -> O((M + K)log(N))
*/
/*
완전 이진 트리로 구성 = heap과 동일

tree size = 2^x > MAXN
즉, data 12개이면, Leaf 노드 개수 = 2^x = 16개, 공간은 16개 필요

핸들링을 위해 0을 사용하지않음.
*/


// tree size = 2^x > MAXN, or roughly approximation = MAXN * 4
int tree[MAXN * 4];              // ~ 2^20 > MAXN 
int leaf, n;                     // leaf idx, # of data

void initLeaf()
{
	// 쓰레기값을 비우는 초기화 꼭 하기
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
	idx += leaf - 1; // idx of a번째 자료
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

	// left boundary와 right boundary가 교차할 때 까지 return 할 min value 값을 수정해 간다.
	while (1)
	{
		if (r < l) break; // 뒤집힘.

		// 1. 이번 l, r이 각 조건에 해당될 때 값을 취한다.
		if (l % 2 == 1) ret += tree[l];
		if (r % 2 == 0) ret += tree[r];

		// 2. 크로스 무빙
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