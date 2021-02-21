#ifndef CHAPTER8_WEIGHTED_GRAPH_EDGE
#define CHAPTER8_WEIGHTED_GRAPH_EDGE

#include <ostream>

template <typename Weight>
class Edge {
   private:
    int _vertex1;
    int _vertex2;
    Weight _weight;

   public:
    Edge(int v1, int v2, Weight w) : _vertex1(v1), _vertex2(v2), _weight(w){};
    Edge() {}
    ~Edge();

    int vertex1() const { return _vertex1; }

    int vertex2() const { return _vertex2; }

    Weight& weight() const { return _weight; }

    int other(int x) const { return x == _vertex1 ? _vertex2 : _vertex1; }

    friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
        os << e.vertex1() << "-" << e.vertex2() << ": " << e._weight
           << std::endl;

        return os;
    }

    bool operator<(Edge<Weight>& e) { return _weight < e.weight(); }
    bool operator>(Edge<Weight>& e) { return _weight > e.weight(); }
    bool operator==(Edge<Weight>& e) { return _weight == e.weight(); }
    bool operator<=(Edge<Weight>& e) { return _weight <= e.weight(); }
    bool operator>=(Edge<Weight>& e) { return _weight >= e.weight(); }
};

template <typename Weight>
Edge<Weight>::~Edge() {}

#endif