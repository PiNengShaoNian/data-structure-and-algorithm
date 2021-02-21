#ifndef CHAPTER8_WEIGHTED_GRAPH_LAZY_PRIM_MST_H
#define CHAPTER8_WEIGHTED_GRAPH_LAZY_PRIM_MST_H

#include <vector>

#include "../chapter4-heap/min-heap.h"
#include "edge.h"

template <typename Graph, typename Weight>
class LazyPrimMST {
   private:
    /* data */
    Graph& graph;
    MinHeap<Edge<Weight>> pq;
    bool* marked;
    Weight mstWeight;
    std::vector<Edge<Weight>> mst;

    void visit(int v) {
        assert(!marked[v]);
        marked[v] = true;

        for (Edge<Weight>* edge : graph.adjacent(v)) {
            if (!marked[edge->other(v)]) {
                pq.insert(*edge);
            }
        }
    }

   public:
    LazyPrimMST(Graph& graph);
    ~LazyPrimMST();
};

template <typename Graph, typename Weight>
LazyPrimMST<Graph, Weight>::LazyPrimMST(Graph& g) : graph(g) {
    int vertices = g.vertices();
    marked = new bool[vertices];

    for (int i = 0; i < vertices; ++i) {
        marked[i] = false;
    }

    mst.clear();
    visit(0);

    while (!pq.isEmpty()) {
        Edge<Weight> e = pq.extractMin();
        if (marked[e.vertex1()] == marked[e.vertex2()]) {
            continue;
        }

        mst.push_back(e);

        if (!marked[e.vertex1()]) {
            visit(e.vertex1());
        } else
            visit(e.vertex2());

        mstWeight = mst[0].weight();

        for (int i = 1; i < mst.size(); ++i) {
            mstWeight += mst[i].weight();
        }
    }
}

template <typename Graph, typename Weight>
LazyPrimMST<Graph, Weight>::~LazyPrimMST() {
    delete[] marked;
}

#endif