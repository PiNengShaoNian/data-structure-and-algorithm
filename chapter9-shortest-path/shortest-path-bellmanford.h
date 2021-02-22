#ifndef CHAPTER9_SHORTEST_PATH_SHORTEST_PATH_BELLMANFORD_H
#define CHAPTER9_SHORTEST_PATH_SHORTEST_PATH_BELLMANFORD_H

#include <vector>

#include "../chapter8-weighted-graph/edge.h"

template <typename Graph, typename Weight>
class ShortestPathBellmanFord {
   private:
    Graph& graph;
    int source;
    Weight* distTo;
    std::vector<Edge<Weight>*> edgeTo;
    bool hasNegativeCycle;

   public:
    ShortestPathBellmanFord(Graph& g, int s) : graph(g), source(s) {
        distTo = new Weight[g.vertices()];

        for (int i = 0; i < g.vertices(); ++i) {
            edgeTo.push_back(nullptr);
        }

        distTo[s] = Weight();
        for (int i = 0; i < g.vertices() - 1; ++i) {
            for (int v = 0; v < g.vertices(); ++v) {
                for (Edge* edge : g.adjacent(v)) {
                    if (!edgeTo[edge->other(v)] ||
                        distTo[v] + edge->weight() < distTo[edge->other(v)]) {
                        distTo[e->other(v)] = edge->weight() + distTo[v];
                        edgeTo[e->other(v)] = edge;
                    }
                }
            }
        }
    }
    ~ShortestPathBellmanFord() { delete[] distTo; }
};

#endif