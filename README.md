# Algorithm-Note-cpp

- This repository is a note of basic implementations and concepts of algorithms for problem solving.

---

## Sort

- Selection Sort
- Insertion Sort
- Merge Sort
- STL sort

## Searching

- [Binary Search](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Searching/binary_search.cpp)
- Decision Problem
  - [경계의 한쪽을 찾는 Decision Problem](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Searching/decision_problem.cpp)
    - [예시 설명](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Searching/binary_search-decision_problem.cpp)
  - [경계 자체를 구하는 Decision Problem (Lower Bound 최대화, Upper Bound 최소화)](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Searching/decision_problem-lb_max_ub_min.cpp)
- References
  - [이분 탐색(Binary Search) 헷갈리지 않게 구현하기](https://www.acmicpc.net/blog/view/109)
  - [정올 - Tutorial : 이진탐색(Binary Search-이진검색)](http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=2857&sca=3010)

## [Graph](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Graph/)

- DFS
- BFS
- Flood Fill
  - [한 회에 여러 칸을 이동하는 경우](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Graph/flood-fill-multiple-moving-at-a-time.cpp#L67-L75)
- [Union-Find](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Graph/union_find.cpp)
- MST
  - [Kruskal](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Graph/mst-kruskal.cpp)
    - [SubTree 를 완성해야 하는 경우](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Graph/mst-kruskal-subtree.cpp)(부분 완성이 됐거나 Cycle 을 포함해도 되는 경우)
  - Prim
- [Dijkstra](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Graph/dijkstra.cpp)
  - [항상 now node 에서 방문 여부를 체크해야한다.](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Graph/dijkstra.cpp#L69C1-L71C27)
  - [SSPS 경로 출력](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Graph/dijkstra-path.cpp#LL39C1-L54C1)

## Data Structure

- [Linked List](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Data_Structure/linked_list.cpp)
- Heap
- [Index Tree](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Data_Structure/idx_tree.cpp)

## Et cetera

- Array(Matrix) Handling

  - [2D array rotation-rotation matrix(회전 변환 행렬 사용)](<https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Matrix(Array)_Handling/2d_array_rotation-rotation_matrix.cpp>)
  - [2D array rotation-general method](<https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Matrix(Array)_Handling/2d_array_rotation-general_method.cpp>)

- Prefix Sum

  - [1D prefix](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Etc/prefix-1d.cpp)
  - [2D prefix](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Etc/prefix-2d.cpp)

- Sliding Window

- [Two Pointers](https://github.com/Jin959/Algorithm-Note-cpp/blob/main/Etc/2pointers.cpp)

---

## References

- cpp reference
  - [cplusplus](https://cplusplus.com/reference/)
  - [cppreference](https://en.cppreference.com/w/)
  - [모두의 코드](https://modoocode.com/135)
- [devdocs](https://devdocs.io/)

- Data Structure and Algorithm

  - [geeksforgeeks](https://www.geeksforgeeks.org/)
  - [수학인듯 과학아닌 공학같은 컴퓨터과학](https://librewiki.net/wiki/시리즈:수학인듯_과학아닌_공학같은_컴퓨터과학/알고리즘_기초)

- visuals
  - [visualgo](https://visualgo.net/en)
  - [pathfinding](https://qiao.github.io/PathFinding.js/visual/) - origin for qiao
