#ifndef CHAPTER4_heap_MIN_HEAP_H
#define CHAPTER4_heap_MIN_HEAP_H

#include <algorithm>
#include <cassert>

template <typename Item>
class MinHeap {
   private:
    Item* data;
    int count;
    int cap;

    void shiftUp(int k) {
        while (k / 2 >= 1 && data[k / 2] > data[k]) {
            std::swap(data[k / 2], data[k]);
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {
            int j = 2 * k;

            if (j + 1 <= count && data[j + 1] < data[j]) ++j;

            if (data[k] <= data[j]) break;

            std::swap(data[k], data[j]);

            k = j;
        }
    }

    void resize(int newSize) {
        Item* temp = new Item[newSize];
        std::copy(data, data + count + 1, temp);

        delete[] data;
        data = temp;
        cap = newSize - 1;
    }

   public:
    MinHeap(size_t capacity = 8) {
        data = new Item[capacity + (size_t)1];
        count = 0;
        cap = capacity;
    }

    MinHeap(Item arr[], int n) {
        data = new Item[n + 1];
        cap = n;
        for (int i = 0; i < n; ++i) {
            data[i + 1] = arr[i];
        }

        count = n;

        for (int i = count / 2; i >= 1; --i) {
            shiftDown(i);
        }
    }

    ~MinHeap() { delete[] data; }

    int size() { return count; }

    bool isEmpty() { return count == 0; }

    void insert(Item item) {
        if (count >= cap) resize(cap * 2 + 1);
        data[count + 1] = item;
        ++count;
        shiftUp(count);
    }

    Item extractMin() {
        assert(count > 0);
        Item ret = data[1];
        std::swap(data[1], data[count]);
        --count;
        shiftDown(1);
        return ret;
    }
};

#endif