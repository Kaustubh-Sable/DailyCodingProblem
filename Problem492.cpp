/**
 * This problem was asked by Google.
 * Given an undirected graph represented as an adjacency matrix and an integer
 * k, write a function to determine whether each vertex in the graph can be
 * colored such that no two adjacent vertices share the same color using at
 * most k colors.
**/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool canColor(vector<vector<int>> &adj_list, int &k);

int main() {
  int n = 4, k = 3;   // No. of vertices, no. of colors
  bool graph[n][n] = { {0, 1, 1, 1},          // adjacency matrix
                       {1, 0, 1, 0},
                       {1, 1, 0, 1},
                       {1, 0, 1, 0} };
  
  // adjacency list:
  vector<vector<int>> adj_list(n+1, vector<int>());
  for(int i=0;i<n;i++)
    for(int j=0;j<i;j++) {
      if(graph[i][j]) {
        adj_list[i].push_back(j);
        adj_list[j].push_back(i);
      }
    }
  
  if(canColor(adj_list, k))
    cout<<"Graph coloring is possible.";
  else
    cout<<"Graph coloring is not possible!";
  
  return 0;
}

bool canColor(vector<vector<int>> &adj_list, int &k) {
  int n = adj_list.size()-1;
  vector<int> color_mapping(n+1, 1);    // initializing all nodes with color 1.
  vector<bool> visited(n+1, false);
  int colors_used = 0;

  // BFS on all vertices.
  for(int v=1; v<=n; v++) {
    
    // check if already visited.
    if(visited[v])
      continue;

    visited[v] = true;
    queue<int> q;
    q.push(v);

    while(!q.empty()) {
      int vert = q.front();
      q.pop();

      for(int i=0;i<adj_list[vert].size();i++) {
        int neighbor_vert = adj_list[vert][i];
        if(color_mapping[vert]==color_mapping[neighbor_vert])
          color_mapping[neighbor_vert] += 1;

        colors_used = max(colors_used, 
                  max(color_mapping[vert], color_mapping[neighbor_vert]));
        
        if(colors_used > k)
          return false;

        if(!visited[neighbor_vert]) {
          visited[neighbor_vert] = true;
          q.push(neighbor_vert);
        }
      }
    }
  }

  return true;
}
