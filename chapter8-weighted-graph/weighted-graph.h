#ifndef chapter8_weighted_graph_weighted_graph_h
#define chapter8_weighted_graph_weighted_graph_h

#include <unordered_set>
#include <vector>

#include "edge.h"

template <typename Weight>
class WeightedGraph {
   private:
    using set = std::unordered_set<Edge<Weight>*>;
    std::vector<set> graph;
    int _vertices;
    int _edges;

   public:
    WeightedGraph(int v) : _vertices(v), _edges(0) {
        graph = std::vector<set>(v, set());
    };

    int edges() { return _edges; }
    int vertices() { return _vertices; }

    set& adjacent(int v) { return graph[v]; }

    void addEdge(int v, int w, Weight weight) {
        Edge<Weight>* edge = new Edge<Weight>(v, w, weight);

        graph[v].insert(edge);
        graph[w].insert(edge);
        ++_edges;
    }

    ~WeightedGraph();
};

template <typename Weight>
WeightedGraph<Weight>::~WeightedGraph() {}

#endif