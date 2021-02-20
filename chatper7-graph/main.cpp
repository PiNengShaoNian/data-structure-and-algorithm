#include <iostream>
#include <string>

#include "connected-components.h"
#include "graph.h"
#include "paths.h"
#include "read-graph.h"

using namespace std;

int main() {
    string filename = "testG1.txt";
    Graph graph(6);

    readGraph(graph, filename);

    assert(graph.edges() == 8);
    assert(graph.hasEdge(1, 2) == true);
    assert(graph.hasEdge(1, 5) == false);
    assert(graph.adjacent(0).size() == 3);

    ConnectedComponents<Graph> cc(graph);
    Paths<Graph> paths(graph, 0);

    vector<int> path = paths.pathTo(3);

    for (int v : path) {
        cout << v << "->";
    }

    return 0;
}