#ifndef CHAPTER7_GRAPGH
#define CHAPTER7_GRAPGH

#include <cassert>
#include <unordered_set>
#include <vector>

class Graph {
   private:
    using set = std::unordered_set<int>;
    int _edges;
    int _vertices;
    std::vector<set> graph;

   public:
    Graph(int v) {
        graph = std::vector<set>(v, set());
        _vertices = v;
        _edges = 0;
    }

    int edges() { return _edges; }

    int vertices() { return _vertices; }

    void addEdge(int v, int w) {
        if (v == w) return;
        if (graph[v].find(w) != graph[v].cend()) return;

        graph[v].insert(w);
        graph[w].insert(v);

        ++_edges;
    }

    set& adjacent(int v) { return graph[v]; }

    bool hasEdge(int v, int w) { return graph[v].find(w) != graph[v].cend(); }
};

#endif