#include <iostream>

#include "lib/graph.h"

int main() {
  Graph g1(6);
  Graph g2(5);
  Graph g3(7);

  cout << "Example 1." << endl;

  g1.AddEdge(0, 1);
  g1.AddEdge(0, 2);
  g1.AddEdge(1, 3);
  g1.AddEdge(1, 4);
  g1.AddEdge(3, 4);
  g1.AddEdge(4, 3);
  g1.AddEdge(2, 5);

  g1.Print();
  Graph::AlgorithmLee(g1, 0);

  cout << "\n\n\n";
  cout << "Example 2." << endl;

  g2.AddEdge(0, 1);
  g2.AddEdge(0, 2);
  g2.AddEdge(0, 4);
  g2.AddEdge(1, 3);
  g2.AddEdge(3, 2);
  g2.AddEdge(4, 2);
  g2.AddEdge(4, 3);

  g2.Print();
  Graph::AlgorithmLee(g2, 1);

  return 0;
}