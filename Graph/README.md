# Graph
-----------------------------
## Intro  

- 방향 그래프(양방향 그래프, (단)방향 그래프), 무방향 그래프
  * 이때, 양방향 그래프 = 무방향 그래프

- Cycle이 하나라도 있으면 순환 그래프이다.

- 방향 그래프인데 비순환인 것을 **DAG(Directed Acyclic Graph)**

- $ex)$ git branch, BlockChain

- 간선으로 연결되지 않은 경우도 있을 수 있다. 각각을 그래프라고 하는 것이 아니라 각 요소를 **그래프 연결요소(Connnected Component)** 라고 한다. 이 요소들 모두를 하나의 그래프로 간주한다.
  > ```mermaid 
  > flowchart LR
  > subgraph 하나의 그래프
  >   subgraph 연결요소 1
  >     1((1)) --- 2((2))
  >     1 --- 3((3))
  >   end
  >   subgraph 연결요소 2
  >     4((4)) --- 8((8))
  >   end
  >   subgraph 연결요소 3
  >     7((7)) --- 5((5)) & 6((6))
  >     9((9)) --- 5 & 6
  >   end
  > end
  > ```

- $cf)$ 간선이 없고 노드 1개만 존재하는 경우 ( $E=0, V=1$ )
  > ```mermaid
  > graph LR
  >   subgraph graph
  >   A((1))
  > end
  > ```
  * **방향성 : 알 수 없다**
  
  * **순환 : 비순환** (하나의 사이클도 존재하지 않는다.)

  * 연결요소(Connnected Component) : 1개
  
- $cf)$ 간선도 없고 노드도 없는 경우 ( $E=0, V=0$ ): 그래프로 본다.
  > ```
  >              빈 graph = graph
  > 
  > 
  > ```
  * **방향성 : 알 수 없다**

  * **순환 : 비순환** (하나의 사이클도 존재하지 않는다.)

  * 연결요소(Connnected Component) : 0개
  
---------------------------
## Adjacency Matrix & Adjacency List

| Complexity |인접 행렬|인접 리스트|
|:-----------:|:--------:|:---------:|
|공간 복잡도| $\uparrow$ | $\downarrow$ |
|탐색 시간 복잡도| $\downarrow$ | $\uparrow$ |

- 인접 행렬은 특정 경로(5 -> 2)를 바로 조회 할 수 있다.

- 인접 리스트는 순차적으로 탐색 해야 특정 경로를 확인 할 수 있다.

---------------------------
## 시간복잡도

- DFS, BFS 모두 최악의 경우 완전 탐색한다.  

- AdjMatrix 사용 시 : $O(V^2)$
  * 인접행렬에 적힌 모든 칸을 탐색할 경우

- AdjList를 사용 시 : $O(V + E)$
  * 이때,  
    $$if \quad V \gg  E \quad \rightarrow \quad O(V + E) \sim O(V)$$  
    $$if \quad V \ll  E \quad \rightarrow \quad O(V + E) \sim O(E)$$  
    따라서 , 도미넌트한 쪽으로 기운다.     
     
- 최단거리를 구할 때는 BFS

--------------------------------
## Backtracking & Pruning

- 백트래킹은 하나의 알고리즘 보다는 패러다임에 가깝다.  

- 가지치기는 백트래킹과 함께 사용되고는 한다.  

- 보통 많은 경우의 수가 있을 때 탐색 수를 줄이기 위해 사용한다.
  * 충분히 큰 Test Case 에서 Queue에 넣을 원소량이 많아지기 때문에 DFS, BFS 별반 다르지 않을 때 BFS는 지양한다.