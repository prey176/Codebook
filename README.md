# Codebook

## 1. binarylifting1.cpp
  This code produces LCA of a given tree using the concept of binary lifting.
  
## 2. binarylifting2.cpp
  This code produces LCA of a given tree using the concept of binary lifting with the use of Ancestors.

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
  
## 5. fordFulkerson.cpp
  1. This code implements the ford fulkerson algorithm which calculates the Maximum Flow.
  
  2. The nodes are ideally should be numbered as 1-indexed. So, if there are v nodes,
  the constructor should be given v+1 nodes.
  
  3. Depending upon the problem check out the addEdge function.
  
  4. The time complexity of the algorithm is O(Ef) where E is the number of Edges and f is the maximum flow (Atleast one). The space complexity is O(V^2 + E).
  
  5. For bipartite graphs, to compute maximum bipartite matching. To get the matching check for rG[u][v] == 0 to check if it is a matching edge where there is an edge between u & v and they are in different sets. 
  
  
  
  
  
  
  
  
  
  
  
