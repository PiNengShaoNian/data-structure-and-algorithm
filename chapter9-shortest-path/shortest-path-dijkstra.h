#ifndef CHPATER_9_SHORTEST_PATH_SHORTEST_PATH_DIJKSTRA_H
#define CHPATER_9_SHORTEST_PATH_SHORTEST_PATH_DIJKSTRA_H

#include <vector>

#include "../chapter4-heap/indexed-min-heap.h"
#include "../chapter8-weighted-graph/edge.h"

template <typename Graph, typename Weight>
class ShortestPathDijkstra {
   private:
    Graph& graph;
    int source;
    Weight* distTo;
    bool* marked;

    std::vector<Edge<Weight>*> edgeTo;

   public:
    ShortestPathDijkstra(Graph& g, int s) : graph(g), source(s) {
        distTo = new Weight[g.vertices()];
        marked = new bool[g.vertices()];

        for (int i = 0; i < g.vertices(); ++i) {
            distTo[i] = Weight();
            marked[i] = false;
            edgeTo[i].push_back(nullptr);
        }

        IndexedMinHeap<Weight> indexedPQ(g.vertices());

        distTo[s] = Weight();
        marked[s] = true;

        indexedPQ.insert(s, distTo[s]);

        while (indexedPQ.size()) {
            int v = indexedPQ.extractMinIndex();

            marked[v] = true;

            for (Edge* edge : g.adjacent(v)) {
                int w = edge->other(w);
                if (!marked[w]) {
                    if (!edgeTo[w] || distTo[v] + edge->weight() < distTo[w]) {
                        distTo[w] = distTo[v] + edge->weight();
                        edgeTo[w] = edge;
                        if (indexedPQ.contains(w)) {
                            indexedPQ.change(w, distTo[w]);
                        } else
                            indexedPQ.insert(w, distTo[w]);
                    }
                }
            }
        }
    }

    ~ShortestPathDijkstra() {
        delete[] marked;
        delete[] distTo;
    }
};

#endif