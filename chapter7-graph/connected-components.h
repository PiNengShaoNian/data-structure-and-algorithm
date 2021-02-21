#ifndef CHAPTER7_GRAPH_CONNECTED_COMPONENTS
#define CHAPTER7_GRAPH_CONNECTED_COMPONENTS

#include <memory>

template <typename Graph>
class ConnectedComponents {
   private:
    Graph& graph;
    bool* visited;
    int* _id;
    int _count;

   public:
    ConnectedComponents(Graph& graph);
    ~ConnectedComponents();
    void dfs(int v);

    int count() { return _count; }

    int id(int v) { return _id[v]; }
};

template <typename Graph>
ConnectedComponents<Graph>::ConnectedComponents(Graph& g) : graph(g) {
    // graph = g;
    visited = new bool[graph.vertices()];
    _id = new int[graph.vertices()];
    _count = 0;

    std::uninitialized_fill_n(visited, graph.vertices(), false);

    for (int i = 0; i < graph.vertices(); ++i) {
        if (!visited[i]) {
            dfs(i);
            ++_count;
        }
    }
};

template <typename Graph>
ConnectedComponents<Graph>::~ConnectedComponents() {
    delete[] visited;
    delete[] _id;
}

template <typename Graph>
void ConnectedComponents<Graph>::dfs(int v) {
    visited[v] = true;
    _id[v] = _count;

    for (int neighbor : graph.adjacent(v)) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

#endif