#include <iostream>

#include "indexed-min-heap.h"
#include "min-heap.h"

using namespace std;

int main() {
    MinHeap<int> heap;

    heap.insert(2);
    heap.insert(3);
    heap.insert(1);

    cout << heap.extractMin() << endl;
    cout << heap.extractMin() << endl;
    cout << heap.extractMin() << endl;

    IndexedMinHeap<double> indexedPQ(3);

    indexedPQ.insert(2, 2);
    indexedPQ.insert(1, 1);
    indexedPQ.insert(0, 0);

    cout << indexedPQ.extractMin() << endl;
    cout << indexedPQ.extractMinIndex() << endl;
    cout << indexedPQ.extractMin() << endl;
    cout << indexedPQ.size() << endl;
    return 0;
}