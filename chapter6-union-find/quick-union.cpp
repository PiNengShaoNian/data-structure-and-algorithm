#include <cassert>
#include <iostream>

class UnionFind {
   private:
    int* parent;
    int* size;
    int count;

   public:
    UnionFind(int n) {
        parent = new int[n];
        size = new int[n];
        count = n;

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    ~UnionFind() {
        delete[] parent;
        delete[] size;
    }

    int find(int p) {
        assert(p >= 0 && p < count);

        while (p != parent[p]) {
            p = parent[p];
        }

        return p;
    }

    bool isConnected(int p, int q) { return find(p) == find(q); }

    void unionElements(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);

        if (pRoot == qRoot) return;

        if (size[pRoot] <= size[qRoot]) {
            parent[pRoot] = qRoot;
            size[qRoot] += size[pRoot];
        } else {
            parent[qRoot] = pRoot;
            size[qRoot] += size[pRoot];
        }
    }
};