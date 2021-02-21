#include <iostream>

#include "edge.h"
#include "weighted-graph.h"

using namespace std;

int main() {
    WeightedGraph<double> graph(4);

    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 2);
    graph.addEdge(0, 3, 3);

    cout << graph.edges() << endl;

    for (Edge<double>* edge : graph.adjacent(0)) {
        cout << *edge << endl;
    }
    
    return 0;
}