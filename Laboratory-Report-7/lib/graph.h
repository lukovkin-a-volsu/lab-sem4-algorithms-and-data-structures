#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <limits>
#include <list>
#include <queue>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::numeric_limits;
using std::queue;
using std::vector;

using uint = unsigned int;

class Graph {
 private:
  uint v_;
  // list of adjacency edges
  list<uint>* adj_;

 public:
  Graph(uint v) : v_(v) { adj_ = new list<uint>[v]; };

  void AddEdge(uint v, uint weight) { adj_[v].push_back(weight); }

  void Print() {
    for (int v = 0; v < v_; v++) {
      cout << "Adjacency list for " << v << " edge: \n:";
      for (uint x : adj_[v]) cout << " - " << x;
      cout << endl;
    }
  }

  static void AlgorithmLee(Graph& graph, uint src) {
    vector<uint> distance(graph.v_, UINT_MAX);
    queue<uint> q;
    distance[src] = 0;
    q.push(src);

    while (!q.empty()) {
      uint u = q.front();
      q.pop();

      for (uint v : graph.adj_[u]) {
        if (distance[v] == UINT_MAX) {
          distance[v] = distance[u] + 1;
          q.push(v);
        }
      }
    }

    cout << "Distance from " << src << " to each edge:" << endl;

    for (int i = 0; i < graph.v_; i++) {
      cout << "Edge " << i << ": ";
      if (distance[i] == UINT_MAX)
        cout << "Unreachable" << endl;
      else
        cout << distance[i] << endl;
    }
  }
};

#endif  // GRAPH_H
