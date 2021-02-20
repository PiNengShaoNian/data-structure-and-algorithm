#include <cassert>
#include <iostream>

using namespace std;

class UnionFind {
   private:
    int* id;
    int count;

   public:
    UnionFind(int n) {
        id = new int[n];
        count = n;
        for (int i = 0; i < n; ++i) {
            id[i] = i;
        }
    }

    int find(int p) {
        assert(p >= 0 && p < count);
        return id[p];
    }

    void unionElements(int p, int q) {
        if (isConnected(p, q)) return;

        int pId = find(p);
        int qId = find(q);

        for (int i = 0; i < count; ++i) {
            if (id[i] == pId) id[i] = qId;
        }
    }

    bool isConnected(int p, int q) { return find(p) == find(q); }

    ~UnionFind() { delete[] id; }
};

int main() {

    return 0;
}