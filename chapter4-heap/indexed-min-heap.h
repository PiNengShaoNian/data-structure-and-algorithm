#ifndef CHPATER4_HEAD_INDEXED_MIN_HEAP_H
#define CHPATER4_HEAD_INDEXED_MIN_HEAP_H

#include <algorithm>
#include <cassert>
#include <memory>

template <typename Item>
class IndexedMinHeap {
   private:
    Item* data;
    int* indexes;
    int* reverse;
    int count;
    int cap;

    void shiftUp(int k) {
        while (k / 2 >= 1 && data[indexes[k / 2]] > data[indexes[k]]) {
            std::swap(indexes[k / 2], indexes[k]);
            reverse[indexes[k / 2]] = k / 2;
            reverse[indexes[k]] = k;
            k /= 2;
        }
    }

    void shiftDown(int k) {
        while (2 * k <= count) {
            int j = 2 * k;

            if (j + 1 <= count && data[indexes[j + 1]] < data[indexes[j]]) ++j;

            if (data[indexes[k]] <= data[indexes[j]]) break;

            std::swap(indexes[k], indexes[j]);
            reverse[indexes[k]] = k;
            reverse[indexes[j]] = j;
            k = j;
        }
    }

    void resize(int newSize) {
        Item* tempData = new Item[newSize];
        int* tempIndexes = new int[newSize];
        std::copy(data, data + count + 1, tempData);
        std::copy(indexes, indexes + count + 1, tempIndexes);

        delete[] data;
        delete[] indexes;
        data = tempData;
        indexes = tempIndexes;
        cap = newSize - 1;
    }

   public:
    IndexedMinHeap(size_t capacity = 8) {
        data = new Item[capacity + (size_t)1];
        indexes = new int[capacity + 1];
        reverse = new int[capacity + 1];

        std::uninitialized_fill_n(reverse, capacity + 1, 0);
        count = 0;
        cap = capacity;
    }

    IndexedMinHeap(Item arr[], int n) {
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

    ~IndexedMinHeap() {
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    int size() { return count; }

    bool isEmpty() { return count == 0; }

    void insert(int i, Item item) {
        assert(i + 1 >= 1);
        if (count >= cap) resize(cap * 2 + 1);
        ++i;
        data[i] = item;
        indexes[count + 1] = i;
        reverse[i] = count + 1;

        ++count;
        shiftUp(count);
    }

    Item extractMin() {
        assert(count > 0);
        Item ret = data[indexes[1]];
        std::swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        --count;
        shiftDown(1);
        return ret;
    }

    int extractMinIndex() {
        assert(count > 0);
        int ret = indexes[1] - 1;
        std::swap(indexes[1], indexes[count]);
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        --count;
        shiftDown(1);
        return ret;
    }

    bool contains(int i) {
        assert(i + 1 >= 1 && i + 1 <= cap);
        return reverse[i + 1] != 0;
    }

    Item getItem(int i) {
        assert(contains(i));
        return data[i + 1];
    }

    void change(int i, Item newItem) {
        assert(contains(i));
        ++i;
        int j = reverse[i];
        shiftDown(j);
        shiftUp(j);
    }
};

#endif