#ifndef CHAPTER7_GRAPH_READ_GRAPH
#define CHAPTER7_GRAPH_READ_GRAPH

#include <cassert>
#include <fstream>
#include <sstream>
#include <string>

template <typename Graph>
void readGraph(Graph &graph, const std::string &filename) {
    std::ifstream file(filename);
    std::string line;
    int vertices, edges;

    assert(file.is_open());

    assert(std::getline(file, line));

    std::stringstream ss(line);

    ss >> vertices >> edges;

    for (int i = 0; i < edges; ++i) {
        assert(std::getline(file, line));
        std::stringstream ss(line);
        int v, w;

        ss >> v >> w;

        graph.addEdge(v, w);
    }
}

#endif