#ifndef CHAPTER7_GRAPH_PATHS
#define CHAPTER7_GRAPH_PATHS

#include <vector>

template <typename Graph>
class Paths {
   private:
    int source;
    Graph& graph;
    bool* visited;
    int* edgeTo;

   public:
    Paths(Graph& g, int s);
    ~Paths();

    void dfs(int v);

    bool hasPath(int v) { return visited[v]; }

    std::vector<int> pathTo(int vertex) {
        std::vector<int> path;

        while (vertex != source) {
            path.push_back(vertex);
            vertex = edgeTo[vertex];
        }

        path.push_back(source);

        return path;
    }
};

template <typename Graph>
Paths<Graph>::Paths(Graph& g, int s) : graph(g) {
    int V = g.vertices();
    visited = new bool[V];
    edgeTo = new int[V];
    source = s;

    for (int i = 0; i < V; ++i) {
        visited[i] = false;
        edgeTo[i] = i;
    }

    dfs(source);
}

template <typename Graph>
Paths<Graph>::~Paths() {
    delete[] visited;
    delete[] edgeTo;
}

template <typename Graph>
void Paths<Graph>::dfs(int v) {
    visited[v] = true;

    for (int neighbor : graph.adjacent(v)) {
        if (!visited[neighbor]) {
            edgeTo[neighbor] = v;
            dfs(neighbor);
        }
    }
}

#endif