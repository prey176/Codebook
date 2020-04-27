# Codebook

## 1. binarylifting1.cpp
  This code produces LCA of a given tree using the concept of binary lifting.
  
## 2. binarylifting2.cpp
  This code produces LCA of a given tree using the concept of binary lifting with the use of Ancestors.
  CONTAINS ERROR!!! FIX IT!!!

## 3. TwoSAT.cpp
    
  1. Given an implication graph, this checks if a solution exists.
  addXor(), addAnd(), addOr() can be used to appropriately add clauses.
    
  2. forceTrue() forces some variable to be true.
     forceFalse() forces some variable to be false.

  3. You can also add additional implications yourself.
  
  4. solve() checks if in the final implication graph, a valid solution exists.
  
  5. mark[u] stores the boolean value of the node (u). You can use mark[] to
  recover the final solution as well.

  6. Notes on Indexing Nodes : (i) u = 2k, !u = 2k + 1 (ii) Nodes are 0-indexed. [0, NUM VERTICES)

## 4. dijkstra.cpp
  This code implements the dijkstra algorithm.
  
## 5. fordFulkerson1.cpp
  1. This code implements the ford fulkerson algorithm which calculates the Maximum Flow.
  
  2. The nodes are ideally should be numbered as 1-indexed. So, if there are v nodes,
  the constructor should be given v+1 nodes.
  
  3. Depending upon the problem check out the addEdge function.
  
  4. The time complexity of the algorithm is O(Ef) where E is the number of Edges and f is the maximum flow (Atleast one). The space complexity is O(V^2 + E).
  

## 6. fordFulkerson2.cpp
  1. This code implements the ford fulkerson algorithm which calculates the Maximum Flow.
  
  2. The nodes are ideally should be numbered as 1-indexed. So, if there are v nodes,
  the constructor should be given v+1 nodes.
  
  3. The time complexity of the algorithm is O(E f log(MAX DEGREE)) where E is the number of Edges and f is the maximum flow (Atleast one). The space complexity is O(V + E).

## 7. bipartiteMatching.cpp
  1. This code implements the Hopcroft-Karp algorithm which calculates the Maximal Matching for bipartite graphs.
  
  2. The nodes on the left and right side are both 1-indexed respectively.
  
  3. The time complexity of the algorithm is O(EV^0.5) and the space complexity is O(V + E).
  
## 8. Mo-offline.cpp
  1. Problem Source - https://codeforces.com/problemset/problem/220/B
  
  2. You could get the major template of Mo Offline Algorithm in it.

## 9. D&C-dpOptimization.cpp
  1. Problem Source - https://codeforces.com/contest/868/problem/F
  
  2. Preconditions -
  
      2.1  The DP Expression should be of this form DP[i][j] = MIN(k <= j)   {DP[i-1][k] + C[k][j]}.
      
      2.2  Let opt(i,j) be the value of k that minimizes the above expression. If opt(i,j)≤opt(i,j+1) for all i,j, then we can apply divide-and-conquer DP.
  
  3. The time complexity is O(n k log n). The Space Complexity is O(n k).
  
  4. Change the update function as per the needs. It doesn't affect the comlexity. This file contains the major template of Divide and Conquer DP Optimization.

## 10. geometry.cpp
  1. May contain bugs. FIX IT.
  
## 11. articulationPoints&Bridges.cpp
  1. Articulation Points are printed are sorted in increasing order and so are the edges (u v where u < v) in increasing order with the first vertex and then the second vertex.
  
  2. This helps us encapsulate the concept of DFS Tree.

## 12. hld1.cpp
  1. Problem Source - https://www.spoj.com/problems/QTREE/
  
  2. This is an example for Heavy Light Decompostion with queries on edges. This will help you get the template for HLD for edge queries.
  
## 13. hld2.cpp
  1. Problem Source - https://www.spoj.com/OI/problems/QTREE3/ , I couldn't submit the problem (100% Not Sure).
  
  2. This is an example for Heavy Light Decompostion with queries on vertices. This will help you get the template for HLD for vertices queries.
