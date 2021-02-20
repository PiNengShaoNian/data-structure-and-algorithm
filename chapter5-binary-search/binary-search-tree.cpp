#include <cassert>
#include <cstddef>
#include <iostream>
using namespace std;

template <typename Key, typename Value>
class BST {
   private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;
        size_t size;

        Node(Key key, Value value)
            : value(value), key(key), right(nullptr), left(nullptr), size(1) {}
    };

    Node* root;

    size_t size(Node* node) {
        if (node) return node->size;
        return 0;
    }

    Node* insert(Node* root, const Key& key, const Value& value) {
        if (!root) return new Node(key, value);

        int cmp = key - root->key;

        if (cmp == 0)
            root->value = value;
        else if (cmp < 0)
            root->left = insert(root->left, key, value);
        else
            root->right = insert(root->right, key, value);

        root->size = size(root->left) + 1 + size(root->right);

        return root;
    }

    Node* find(Node* root, const Key& key) {
        if (!root) return nullptr;

        int cmp = key - root->key;

        if (cmp == 0)
            return root;
        else if (cmp < 0)
            return find(root->left, key);
        else
            return find(root->right, key);
    }

    void free(Node* node) {
        if (!node) return;

        free(node->left);
        free(node->right);

        delete node;
    }

    Node* min(Node* root) {
        if (!root->left) return root;

        return min(root->left);
    }

    Node* deleteMin(Node* root) {
        if (!root->left) {
            Node* node = root->right;
            delete root;
            return node;
        }

        root->left = deleteMin(root->left);
        root->size = size(root->left) + 1 + size(root->right);

        return root;
    }

    Node* erase(const Key& key, Node* root) {
        assert(root != nullptr);
        if (key < root->key) {
            root->left = erase(key, root->left);
        } else if (key > root->key) {
            root->right = erase(key, root->right);
        } else {
            if (!root->left) {
                Node* node = root->right;
                delete root;
                return node;
            }

            if (!root->right) {
                Node* node = root->left;
                delete root;
                return node;
            }

            Node* aux = min(root->right);

            root->value = aux->value;
            root->key = aux->key;
            root->right = deleteMin(root->right);
        }

        root->size = size(root->left) + 1 + size(root->right);
        return root;
    }

   public:
    BST(/* args */) : root(nullptr) {}

    ~BST() { free(root); };

    size_t size() { return size(root); }

    void insert(const Key& key, const Value& value) {
        root = insert(root, key, value);
    }

    Value* find(const Key& key) {
        Node* node = find(root, key);
        if (!node) return nullptr;
        return &node->value;
    }

    void erase(const Key& key) {
        if (!contains(key)) return;

        root = erase(key, root);
    }

    bool isEmpty() { return size() == 0; }

    void clear() { root = nullptr; }

    bool contains(const Key& key) { return find(root, key) != nullptr; }
};

int main() {
    BST<int, int> bst;

    bst.insert(1, 1);
    bst.insert(2, 2);
    bst.insert(3, 3);

    assert(bst.size() == 3);

    bst.insert(2, 5);
    bst.insert(1, 1);

    assert(bst.size() == 3);
    bst.insert(4, 4);
    assert(bst.size() == 4);

    assert(*bst.find(1) == 1);
    assert(*bst.find(4) == 4);
    assert(bst.find(5) == nullptr);
    assert(*bst.find(2) == 5);
    assert(bst.contains(3) == true);
    assert(bst.contains(6) == false);

    bst.clear();

    assert(bst.size() == 0);

    bst.insert(2, 2);
    bst.insert(1, 1);
    bst.insert(3, 3);

    assert(bst.contains(1) == true);
    bst.erase(1);
    assert(bst.contains(1) == false);
    assert(bst.size() == 2);

    assert(bst.contains(2) == true);
    bst.erase(2);
    assert(bst.contains(2) == false);
    assert(bst.size() == 1);

    assert(bst.contains(3) == true);
    bst.erase(3);
    assert(bst.contains(3) == false);
    assert(bst.size() == 0);

    return 0;
}