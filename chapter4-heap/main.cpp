#include <iostream>

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
    return 0;
}