vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
{        
      vector <int> graph [numCourses];
      vector <int> indegree (numCourses,0);

      for (vector <int> a : prerequisites)
      {
          /*a [1] is a pre requisite of a [0] */
          graph [a [1]].push_back (a [0]);
          indegree [a [0]] += 1;
      }

      vector <int> topoOrder;

      queue <int> q;
      for (int i = 0 ; i < numCourses; i++)
      {
          if (indegree [i] == 0) q.push (i);
      }

      while (not q.empty())
      {
          int u = q.front(); q.pop();
          topoOrder.push_back(u);

          for (int a : graph [u])
          {
              indegree [a] -= 1;
              if (indegree [a] == 0) q.push (a);
          }
      }        
      if (topoOrder.size() < numCourses) topoOrder.clear();
      return topoOrder;

}
